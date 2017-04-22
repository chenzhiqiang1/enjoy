/*
��Ŀ������
    ����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������

���룺
    ������ܰ����������������������EOF������
    ����ÿ�����԰���������ĵ�һ��Ϊһ������n(1<=n<=1000000)�� n����Ҫ����Ĳ����Ĳ�������
    ��������n�У�ÿ�п�ʼ��һ����ĸCi��
    Ci=��s��ʱ��������һ������k������kѹ��ջ��
    Ci=��o��ʱ������ջ��Ԫ�ء�

�����
    ��Ӧÿ�����԰����е�ÿ��������
    ��ջ��Ϊ�գ������Ӧ��ջ����СԪ�ء��������NULL��

�������룺
    7
    s 3
    s 4
    s 2
    s 1
    o
    o
    s 0

���������
    3
    3
    2
    1
    2
    3
    0
*/

/* 
�������������ģ��ջ 
*/  
typedef int ElemType;  
#define MAX 100000  //ջ�����  
#include<stdio.h>  
      
int top = -1;  
/* 
��ջ������ָ��Ϊtopʱ����ջA��ѹ������data 
*/  
bool push(int *A,ElemType data)  
{  
    if(top>=MAX-1 || top<-1)  
        return false;  
      
    A[++top] = data;  
    return true;  
}  
      
/* 
��ջ������ָ��Ϊtopʱ����ջ 
*/  
bool pop()  
{  
    if(top<0)  
        return false;  
      
    top--;  
    return true;  
}  
      
/* 
ջ����ǰ����ָ��Ϊtop��Min����������ҲΪMAX�� 
��Min����ЧԪ������ջA�е�Ԫ�ظ�����ͬ�� 
���Ķ�Ӧλ����������ջA��Ӧλ�õ�ջ����һ����Ԫ���е���Сֵ 
*/  
void minAll(int *A,int *Min)  
{  
    if(top>MAX-1)  
        return ;  
    Min[0] = A[0];  
    int i;  
    for(i=1;i<=top;i++)  
    {  
        if(Min[i-1] > A[i])  
            Min[i] = A[i];  
        else  
            Min[i] = Min[i-1];  
    }  
}  
      
/* 
����ջ��Ϊtopʱջ��Ԫ�ص���Сֵ 
*/  
int min(int *Min)  
{  
    return Min[top];  
}  
      
int main()  
{  
      
    int n;  
    int A[MAX];  
    int Min[MAX];  
      
    while(scanf("%d",&n) != EOF)  
    {  
        int i;  
        for(i=0;i<n;i++)  
        {  
            char ci;  
            while(getchar() != '\n')  
                continue;  
            scanf("%c",&ci);  
            if(ci == 's')  
            {  
                ElemType k;  
                scanf("%d",&k);  
                push(A,k);  
            }  
            if(ci == 'o')  
            {  
                pop();  
            }  
                  
            minAll(A,Min);  
            if(top<0)  
                printf("NULL\n");  
            else  
                printf("%d\n",min(Min));  
        }  
    }  
    return 0;  
}  


/**************************************************************
    Problem: 1522
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:60 ms
    Memory:1624 kb
****************************************************************/