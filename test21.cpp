/*
题目描述：
    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。

输入：
    每个测试案例包括2行：
    第一行输入一个整数n（1<=n<=100000），表示数组中元素的个数。
    第二行输入n个整数，表示数组中的每个元素，这n个整数的范围是[1,1000000000]。

输出：
    对应每个测试案例，输出出现的次数超过数组长度的一半的数，如果没有输出-1。

样例输入：
    9
    1 2 3 2 2 2 5 4 2

样例输出：
    2

4、网上很流行的做法，由于该数字的出现次数比所有其他数字出现次数的和还要多，因此可以考虑在遍历数组时保存两个值：一个是数组中的一个数字，一个是次数，。当遍历到下一个数字时，如果下一个数字与之前保存的数字相同，则次数加1，如果不同，则次数减1，如果次数为0，则需要保存下一个数字，并把次数设定为1。由于我们要找的数字出现的次数比其他所有数字的出现次数之和还要大，则要找的数字肯定是组后一次把次数设为1时对应的数字。该方法的时间复杂度为O(n)，空间复杂度为O(1)。
*/

#include<stdio.h>  
#include<stdlib.h>   
bool IsExisted;  
  
/* 
判断关键字key在数组A中出现的次数是否超过一半 
*/  
bool IsMoreThanHalf(int *A,int len,int key)  
{  
    int times = 0;  
    int i;  
    for(i=0;i<len;i++)  
        if(A[i] == key)  
            times++;  
    if(2*times <= len)  
        return false;  
    else  
        return true;  
}  
  
/* 
找出出现次数超过一半的数字 
*/  
int MoreThanHalfDP(int *A,int len)  
{  
    if(A==NULL || len<1)  
    {  
        IsExisted = false;  
        return -1;  
    }  
      
    int result = A[0];  
    int times = 1;  
    int i;  
    for(i=1;i<len;++i)  
    {  
        if(times == 0)  
        {  
            result = A[i];  
            times = 1;  
        }  
        else if(A[i] == result)  
            ++times;  
        else  
            --times;  
    }  
    if(!IsMoreThanHalf(A,len,result))  
    {  
        IsExisted = false;  
        return -1;  
    }  
    return result;  
}  
  
int main()  
{  
    int n;  
    while(scanf("%d",&n) != EOF)  
    {  
        int *A = (int *)malloc(sizeof(int)*n);  
        if(A == NULL)  
            exit(EXIT_FAILURE);  
  
        int i;  
        for(i=0;i<n;i++)  
            scanf("%d",A+i);  
  
        IsExisted = true;  
        int key = MoreThanHalfDP(A,n);  
        if(IsExisted)  
            printf("%d\n",key);  
        else  
            printf("-1\n");  
    }  
    return 0;  
} 

/**************************************************************
    Problem: 1370
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:50 ms
    Memory:1304 kb
****************************************************************/