#include <stdio.h>  
#include <stdlib.h>  
  
#define OK 1  
#define ERROR 0  
#define QUEUE_SIZE 100  
  
typedef  int ElemType;  
typedef struct Qnode  
{  
    ElemType *base;  
    int front;  
    int rear;  
    int count;  
} Qnode;  

int Init(Qnode &qq)  
{  
    qq.base = (ElemType*)malloc(QUEUE_SIZE * sizeof(ElemType));  
    if (qq.base == NULL) return ERROR;  
    qq.front = 0;  
    qq.rear = 0;  
    qq.count = 0;  
    return OK;  
}  
  
int EnQueue(Qnode &qq, ElemType e)  
{  
    if ((qq.rear + 1) % QUEUE_SIZE == qq.front)  
		return ERROR;  
    qq.base[qq.rear] = e;  
    qq.rear = (qq.rear + 1)%QUEUE_SIZE;  
    qq.count++;  
    return OK;  
}  
  
int DeQueue(Qnode &qq, ElemType &e)  
{  
    if (qq.rear == qq.front)  
		return ERROR;  
    e = qq.base[qq.front];  
    qq.front = (qq.front + 1) % QUEUE_SIZE;  
    qq.count--;  
    return OK;  
}  
  
int GetTop(Qnode &qq, ElemType &e)  
{  
    if (qq.rear == qq.front)  
		return ERROR;  
    e = qq.base[qq.front];  
    return OK;  
}  

int Destroy(Qnode qq)  
{  
    free(qq.base);  
    qq.base = NULL;  
    qq.count = 0;  
    return OK;  
}  
int main()  
{  
    Qnode qq;  
    Init(qq);  
    int m, i;  
    printf("how many nums?\n");  
    scanf("%d", &m);  
    for (i = 0; i < m; i++)  
    {  
        int e;  
        scanf("%d", &e);  
        EnQueue(qq, e);  
    }  
    int e;  
    GetTop(qq, e);  
    printf("%d\n" , e);  
    for (i = 0; i < m; i++)  
    {  
        DeQueue(qq, e);  
        printf("%d ", e);  
    }  
    printf("\n");  
    system ("pause");  
    return 0;  
} 