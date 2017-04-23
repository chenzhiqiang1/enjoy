/*
题目描述：
    输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵：
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

输入：
    输入可能包含多个测试样例，对于每个测试案例，
    输入的第一行包括两个整数m和n(1<=m,n<=1000)：表示矩阵的维数为m行n列。
    接下来的m行，每行包括n个整数，表示矩阵的元素，其中每个元素a的取值范围为(1<=a<=10000)。

输出：
    对应每个测试案例，输出一行，
    按照从外向里以顺时针的顺序依次打印出每一个数字，每个数字后面都有一个空格。

样例输入：
    4 41 2 3 45 6 7 89 10 11 1213 14 15 16

样例输出：
    1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 

    这道题目没有涉及到任何算法，主要考察逻辑思维，注意各种情况的分析，循环退出的条件等。这道题目不像之前的那样，输出要特别注意最后一个输出元素的输出格式了。
*/

#include<stdio.h>  
#include<stdlib.h>  
      
/* 
顺时针打印一圈 
*/  
void PrintMatrixCirclely(int **num,int m,int n,int start)  
{  
    int endX = n-start-1;  
    int endY = m-start-1;  
      
    int i;  
    //从左到右打印行  
    for(i=start;i<=endX;i++)  
        printf("%d ",num[start][i]);  
      
    //从上到下打印列  
    if(start < endY)  
    {  
        for(i=start+1;i<=endY;i++)  
            printf("%d ",num[i][endX]);  
    }  
      
    //从右向左打印行  
    if(start<endX && start<endY)  
    {  
        for(i=endX-1;i>=start;i--)  
            printf("%d ",num[endY][i]);  
    }  
      
    //从下到上打印列  
    if(start<endX && start<endY-1)  
    {  
        for(i=endY-1;i>=start+1;i--)  
        {  
            printf("%d ",num[i][start]);  
        }  
    }  
}  
      
/* 
顺时针打印矩阵 
*/  
void PrintMatrixClockwisely(int **num,int m,int n)  
{  
    if(num==NULL || m<=0 || n<=0)  
        return;  
    int start = 0;  
    while(m>2*start && n>2*start)  
    {  
        PrintMatrixCirclely(num,m,n,start);  
        start++;  
    }  
}  
      
int main()  
{  
    int m,n;  
    while(scanf("%d %d",&m,&n) != EOF)  
    {  
        int **num = (int **)malloc(m*sizeof(int *));  
        if(num == NULL)  
            exit(EXIT_FAILURE);  
        int i;  
        for(i=0;i<m;i++)  
        {  
            num[i] = (int *)malloc(n*sizeof(int));  
            if(num[i] == NULL)  
                exit(EXIT_FAILURE);  
        }  
      
        int j;  
        for(i=0;i<m;i++)  
            for(j=0;j<n;j++)  
                scanf("%d",&num[i][j]);  
      
        PrintMatrixClockwisely(num,m,n);  
        printf("\n");  
      
        for(i=0;i<m;i++)  
        {  
            free(num[i]);  
            num[i] = NULL;  
        }  
        free(num);  
        num = NULL;       
    }  
    return 0;  
}  

/**************************************************************
    Problem: 1391
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:520 ms
    Memory:912 kb
****************************************************************/