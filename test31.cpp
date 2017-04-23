/*
��Ŀ������
    ����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣

���룺
    ÿ�������ļ�����һ����԰�����
    ����ÿ�����԰�������һ������һ��n����������������ֵĸ�����
    ��������һ������n�����������������е�n������

�����
    ��Ӧÿ�����԰�����
    ����һ��n�����֣��������������顣ע�⣬���ֺ�����֮����һ���ո���������һ�����ֺ���û�пո�

�������룺
    5
    1 2 3 4 5

���������
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
        //����  
        if((A[i]&1) != 0)  
            B[j++] = A[i];  
    }  
    for(i=0;i<n;i++)  
    {  
        //ż��  
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
        //ע�������ʽ  
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