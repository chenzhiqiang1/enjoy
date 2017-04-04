/*
题目描述：
    LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。
    现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。

输入：
    输入有多组数据。
    每组数据包含两行,第一行输入一个正数n(0<=n<=14),表示从扑克牌中抽出的扑克牌数。接下来的一行输入n个数,表示从这幅扑克牌中抽出的牌。如果n=0,则结束输入。

输出：
    对应每组数据,如果抽出的牌是顺子,则输出“So Lucky!”。否则,输出“Oh My God!”。

样例输入：
    5
    3 5 1 0 4
    5
    3 5 4 7 6
    5
    3 5 7 4 8
    0

样例输出：
    So Lucky!
    So Lucky!
    Oh My God!

    九度上把这道题目改成了一副扑克牌有4张大小王，这里姑且不管它最多几个0，就题目来说，不严谨，很含糊，比如这里没有对顺子给出比较严谨的定义，5个以下的连续数字算是顺子吗？现实中要至少5个才算顺子的，而且如果假设3个牌也算顺子，那如果输入的是3个0呢，这有点太牵强了！看论坛里面好多人吐槽。总之，不管那么多，这道题目无论它怎么坑爹，用剑指offer上的思路写的代码AC是没问题的，因为这里不管你0有多少个（只要不大于数组的长度就可）都OK。
    我之前想避开排序，或者开辟哈希数组，就遍历一遍求出最大值，最小值，0出现的次数，而后根据三者间的关系来判断是否构成顺子，但这要在数组中没有重复元素的前提下，而要判断数组中没有重复元素，要么要排序，要么就要借助哈希数组统计元素出现的次数，最终还是省不掉。无奈最后还是用书上的思路，为求代码的简洁性，一样用C语言自带的快速排序函数，当然用计数排序（其实跟开辟哈希数组就是一个思路）更快点，但对n最大为14的情况，二者效率差不了太多。
*/

/**************************************************************
    Problem: 1355
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:912 kb
****************************************************************/

#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
  
int mycompare(const void *data1,const void *data2)  
{  
    return *(int *)data1 - *(int *)data2;  
}  
  
  
bool IsContinuous(int *arr,int len)  
{  
    if(arr==NULL || len<1)  
        return false;  
  
    qsort(arr,len,sizeof(int),mycompare);  
  
    int NumOf0 = 0;     //0的个数  
    int NumOfGap = 0;  //空缺的个数  
    int i;  
    for(i=0;i<len-1;i++)  
    {  
        if(arr[i] == 0)  
            NumOf0++;  
        else  
        {  
            if(arr[i] == arr[i+1])  
                return false;  
            else  
                NumOfGap += arr[i+1]-arr[i]-1;  
        }  
    }  
    return (NumOfGap>NumOf0)?false:true;  
}  
  
int main()  
{  
    int n;  
    int arr[15];  
    memset(arr,0,sizeof(arr));  
    while(scanf("%d",&n)!=EOF && n!=0)  
    {  
        int i;  
        for(i=0;i<n;i++)  
            scanf("%d",arr+i);  
  
        bool can = IsContinuous(arr,n);  
        if(can)  
            printf("So Lucky!\n");  
        else  
            printf("Oh My God!\n");  
    }  
    return 0;  
} 