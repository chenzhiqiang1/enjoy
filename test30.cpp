/*
��Ŀ������
    ����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬����������¾���
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

���룺
    ������ܰ��������������������ÿ�����԰�����
    ����ĵ�һ�а�����������m��n(1<=m,n<=1000)����ʾ�����ά��Ϊm��n�С�
    ��������m�У�ÿ�а���n����������ʾ�����Ԫ�أ�����ÿ��Ԫ��a��ȡֵ��ΧΪ(1<=a<=10000)��

�����
    ��Ӧÿ�����԰��������һ�У�
    ���մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�ÿ�����ֺ��涼��һ���ո�

�������룺
    4 41 2 3 45 6 7 89 10 11 1213 14 15 16

���������
    1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 

    �����Ŀû���漰���κ��㷨����Ҫ�����߼�˼ά��ע���������ķ�����ѭ���˳��������ȡ������Ŀ����֮ǰ�����������Ҫ�ر�ע�����һ�����Ԫ�ص������ʽ�ˡ�
*/

#include<stdio.h>  
#include<stdlib.h>  
      
/* 
˳ʱ���ӡһȦ 
*/  
void PrintMatrixCirclely(int **num,int m,int n,int start)  
{  
    int endX = n-start-1;  
    int endY = m-start-1;  
      
    int i;  
    //�����Ҵ�ӡ��  
    for(i=start;i<=endX;i++)  
        printf("%d ",num[start][i]);  
      
    //���ϵ��´�ӡ��  
    if(start < endY)  
    {  
        for(i=start+1;i<=endY;i++)  
            printf("%d ",num[i][endX]);  
    }  
      
    //���������ӡ��  
    if(start<endX && start<endY)  
    {  
        for(i=endX-1;i>=start;i--)  
            printf("%d ",num[endY][i]);  
    }  
      
    //���µ��ϴ�ӡ��  
    if(start<endX && start<endY-1)  
    {  
        for(i=endY-1;i>=start+1;i--)  
        {  
            printf("%d ",num[i][start]);  
        }  
    }  
}  
      
/* 
˳ʱ���ӡ���� 
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