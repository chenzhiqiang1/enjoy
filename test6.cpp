/*
题目描述：
    每年六一儿童节,JOBDU都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为JOBDU的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为1的小朋友开始报数。每次喊到m的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续1...m报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到JOBDU名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？

输入：
    输入有多组数据。
    每组数据一行,包含2个整数n(0<=n<=1,000,000),m(1<=m<=1,000,000),n,m分别表示小朋友的人数(编号1....n-1,n)和HF指定的那个数m(如上文所述)。如果n=0,则结束输入。

输出：
    对应每组数据,输出最后拿到大奖的小朋友编号。

样例输入：
    1 10
    8 5
    6 6
    0

样例输出：
    1
    3
    4
*/
#include<stdio.h>  
      
typedef struct Node  
{  
    int next;   //下一个元素的编号  
    int num;    //编号，从1开始  
}Node;  
      
Node arr[1000000];  
      
int FindLastRemaining(int n,int m)  
{  
    if(n<1 || m<1)  
        return 0;  
      
    int start = 1;  
    int current = start;  
    int pre = current;  
    while(start != arr[start].next)  
    {  
        //找到待删元素和它的前一个元素  
        int i;  
        for(i=0;i<m-1;i++)  
        {  
            pre = current;  
            current = arr[current].next;  
        }  
              
        //删除元素，重新建立连接  
        arr[pre].next = arr[current].next;  
        start = arr[pre].next;  
        current = start;  
    }  
    return arr[start].num;  
}  
      
int main()  
{  
    int n;  
    while(scanf("%d",&n) != EOF && n != 0)  
    {  
        int m;  
        scanf("%d",&m);  
      
        //将数据连成环  
        int i;  
        for(i=1;i<=n;i++)  
        {  
            arr[i].num = i;  
            if(i == n)  
                arr[i].next = 1;  
            else  
                arr[i].next = i+1;  
        }  
      
        printf("%d\n",FindLastRemaining(n,m));  
    }  
    return 0;  
}  


/**************************************************************
    Problem: 1356
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:290 ms
    Memory:912 kb
****************************************************************/
//#include<stdio.h>  
//      
//int LastRemaining(int n,int m)  
//{  
//    if(n<1 || m<1)  
//        return 0;  
//      
//    int last = 0;  
//    int i;  
//    for(i=2;i<=n;i++)  
//        last = (last + m)%i;  
//    return last;  
//}  
//      
//int main()  
//{  
//    int n;  
//    while(scanf("%d",&n) != EOF && n != 0)  
//    {  
//        int m;  
//        scanf("%d",&m);  
//        printf("%d\n",LastRemaining(n,m)+1);  
//    }  
//    return 0;  
//}  

