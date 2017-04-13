/*
题目描述：
    HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天JOBDU测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？

输入：
    输入有多组数据,每组测试数据包括两行。
    第一行为一个整数n(0<=n<=100000),当n=0时,输入结束。接下去的一行包含n个整数(我们保证所有整数属于[-1000,1000])。

输出：
    对应每个测试案例,需要输出3个整数单独一行,分别表示连续子向量的最大和、该子向量的第一个元素的下标和最后一个元素的下标。若是存在多个子向量,则输出起始元素下标最小的那个。

样例输入：
    3
    -1 -3 -2
    5
    -8 3 2 0 5
    8
    6 -3 -2 7 -15 1 2 2
    0

样例输出：
    -1 0 0
    10 1 4
    8 0 3

    前面有专门写了一篇求最大连续子数个组的文章，见这里：http://blog.csdn.net/ns_code/article/details/20942045。这里的第三种做法，要在数组中既有负数又有整数的情况下才能得到正确的结果。而这里的测试样例中有全负的情况，因此，跟上面的求解会有些细节上的不同，而且这里除了要求出最大连续子数组的和，还要求出该最大连续子数组，因此要另设两个变量保存该连续子数组的起始和结束的位置。
*/

#include<stdio.h>  
#include<stdlib.h>   
bool flag;  
      
int MaxSubSum(int *arr,int len,int *indexBegin,int *indexEnd)  
{  
    if(arr==NULL || len<1)  
    {  
        flag = false;  
        return -1;  
    }  
      
    int i;  
    int MaxSum;  
    int CurSum;  
    int CurBegin; //当前的CurSum的开始处的索引  
    int CurEnd;  //当前的CurSum的结束处的索引  
    for(i=0;i<len;i++)  
    {  
        if(i == 0)  
        {  
            //先用第一个元素初始化  
            *indexBegin = 0;  
            *indexEnd = 0;  
            CurBegin = 0;  
            CurEnd = 0;  
            MaxSum = arr[i];  
            CurSum = arr[i];  
        }  
        else  
        {  
            //前面的和小于0，抛弃前面的和，从当前元素重新开始计算  
            if(CurSum < 0)  
            {  
                CurSum = arr[i];  
                CurBegin = i;  
                CurEnd = i;  
            }  
            else  
            {  
                CurSum += arr[i];  
                CurEnd = i;  
            }  
            if(CurSum > MaxSum)  
            {  
                MaxSum = CurSum;  
                //如果当前和大于前面出现的最大和，  
                //则替换掉最大和的开始索引和结束索引  
                *indexBegin = CurBegin;  
                *indexEnd = CurEnd;  
            }  
        }  
    }  
    return MaxSum;  
}  
      
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF && n!=0)  
    {  
        int *arr = (int *)malloc(sizeof(int)*n);  
        if(arr == NULL)  
            exit(EXIT_FAILURE);  
      
        int i;  
        for(i=0;i<n;i++)  
            scanf("%d",arr+i);  
      
        flag = true;  
        int indexBegin,indexEnd;  
        int result = MaxSubSum(arr,n,&indexBegin,&indexEnd);      
        if(flag)  
        {  
            printf("%d ",result);  
            printf("%d ",indexBegin);  
            printf("%d\n",indexEnd);  
        }  
      
        free(arr);  
        arr = NULL;  
    }  
    return 0;  
}  
/**************************************************************
    Problem: 1372
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:450 ms
    Memory:1304 kb
****************************************************************/