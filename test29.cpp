/*
题目描述：
    定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

输入：
    输入可能包含多个测试样例，输入以EOF结束。
    对于每个测试案例，输入的第一行为一个整数n(1<=n<=1000000)， n代表将要输入的操作的步骤数。
    接下来有n行，每行开始有一个字母Ci。
    Ci=’s’时，接下有一个数字k，代表将k压入栈。
    Ci=’o’时，弹出栈顶元素。

输出：
    对应每个测试案例中的每个操作，
    若栈不为空，输出相应的栈中最小元素。否则，输出NULL。

样例输入：
    7
    s 3
    s 4
    s 2
    s 1
    o
    o
    s 0

样例输出：
    3
    3
    2
    1
    2
    3
    0
*/

/* 
本程序采用数组模拟栈 
*/  
typedef int ElemType;  
#define MAX 100000  //栈的深度  
#include<stdio.h>  
      
int top = -1;  
/* 
在栈顶索引指针为top时，向栈A中压入数据data 
*/  
bool push(int *A,ElemType data)  
{  
    if(top>=MAX-1 || top<-1)  
        return false;  
      
    A[++top] = data;  
    return true;  
}  
      
/* 
在栈顶索引指针为top时，出栈 
*/  
bool pop()  
{  
    if(top<0)  
        return false;  
      
    top--;  
    return true;  
}  
      
/* 
栈顶当前索引指针为top，Min数组最大深度也为MAX， 
且Min的有效元素数与栈A中的元素个数相同， 
它的对应位置用来保存栈A对应位置到栈底这一部分元素中的最小值 
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
返回栈顶为top时栈中元素的最小值 
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