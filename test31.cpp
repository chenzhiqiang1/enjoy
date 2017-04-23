/*
题目描述：
    输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

输入：
    每个输入文件包含一组测试案例。
    对于每个测试案例，第一行输入一个n，代表该数组中数字的个数。
    接下来的一行输入n个整数。代表数组中的n个数。

输出：
    对应每个测试案例，
    输入一行n个数字，代表调整后的数组。注意，数字和数字之间用一个空格隔开，最后一个数字后面没有空格。

样例输入：
    5
    1 2 3 4 5

样例输出：
    1 3 5 2 4
*/

#include<stdio.h>  
#include<stdlib.h>  
      
void MoveOddEven(int *A,int n)  
{  
    if(A==NULL || n<2)  
        return;  
    int *B = (int *)malloc(n*sizeof(int));    
    if(B == NULL)  
        exit(EXIT_FAILURE);  
      
    int i;  
    int j = 0;  
    for(i=0;i<n;i++)  
    {  
        //奇数  
        if((A[i]&1) != 0)  
            B[j++] = A[i];  
    }  
    for(i=0;i<n;i++)  
    {  
        //偶数  
        if((A[i]&1) == 0)  
            B[j++] = A[i];  
    }  
      
    for(i=0;i<n;i++)  
    {  
        A[i] = B[i];  
    }  
      
    free(B);  
    B = NULL;  
}  
      
int main()  
{  
    int i,n;  
    scanf("%d",&n);  
    int *A = (int *)malloc(n*sizeof(int));  
    if(A == NULL)  
        exit(EXIT_FAILURE);  
    for(i=0;i<n;i++)  
        scanf("%d",A+i);  
    MoveOddEven(A,n);  
    for(i=0;i<n;i++)  
    {  
        //注意输出格式  
        if(i == n-1)  
            printf("%d\n",A[i]);  
        else  
            printf("%d ",A[i]);  
    }  
    free(A);  
    A = NULL;  
    return 0;  
}  
/**************************************************************
    Problem: 1516
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:80 ms
    Memory:1692 kb
****************************************************************/