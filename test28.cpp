/*
题目描述：
    输入两个链表，找出它们的第一个公共结点。

输入：
    输入可能包含多个测试样例。
    对于每个测试案例，输入的第一行为两个整数m和n(1<=m,n<=1000)：代表将要输入的两个链表的元素的个数。
    接下来的两行，第一行为第一个链表的所有元素，中间用空格隔开。第二行为第二个链表的所有元素，中间用空格隔开。

输出：
    对应每个测试案例，
    输出两个链表的第一个公共结点的值。
    如果两个链表没有公共结点，则输出“My God”。

样例输入：
    5 4
    1 2 3 6 7
    4 5 6 7
    3 3
    1 5 7
    2 4 7
    2 3
    1 3
    4 5 6

样例输出：
    6
    7
    My God

    画图有助于我们理解，画图会发现如果二者有公共结点，则公共节点后面的节点也都是公共节点。用两个辅助栈，将两个链表从头分别压入栈，最后二者出栈，最后一个相同的出栈元素即为公共节点。但这样需要开辟两个栈的空间，实际上，可以不用开辟空间，分别求出二者的长度，求出二者的差dis，而后将指向长的链表的指针先在长链表上走dis步，而两个链表同时走，二者会同时走到第一个公共节点处。
*/
#include<stdio.h>  
#include<stdlib.h>  
      
typedef struct Node  
{  
    int data;  
    struct Node *next;  
}Node,*pNode;  
      
/* 
获取链表的长度 
*/  
int getLength(pNode pHead)  
{  
    int len = 0;  
    pNode pCur = pHead;  
    while(pCur != NULL)  
    {  
        len++;  
        pCur = pCur->next;  
    }  
    return len;  
}  
      
/* 
求两个链表的第一个公共节点 
*/  
pNode FindFirstCommonNode(pNode pHead1,pNode pHead2)  
{  
    if(pHead1==NULL ||pHead2==NULL)  
        return NULL;  
      
    int len1 = getLength(pHead1);  
    int len2 = getLength(pHead2);  
    pNode pListLong = pHead1;  
    pNode pListShort = pHead2;  
    int distance = len1-len2;  
    int shortLength = len2;  
    if(len1 < len2)  
    {  
        pListLong = pHead2;  
        pListShort = pHead1;  
        distance = len2-len1;  
        shortLength = len1;  
    }  
          
    int i;  
    for(i=0;i<distance;i++)  
        pListLong = pListLong->next;  
    for(i=0;i<shortLength;i++)  
    {  
        if(pListLong->data == pListShort->data)  
            break;  
        pListLong = pListLong->next;  
        pListShort = pListShort->next;  
    }  
    return pListLong;  
}  
      
int main()  
{  
    int m,n;  
    while(scanf("%d %d",&m,&n) != EOF)  
    {  
        pNode pHead1 = NULL;  
        if(m>0)  
        {  
            int data;  
            scanf("%d",&data);  
            pHead1 = (pNode)malloc(m*sizeof(Node));  
            if(pHead1 == NULL)  
                exit(EXIT_FAILURE);  
            pHead1->data = data;  
            pHead1->next = NULL;  
      
            pNode pCur = pHead1;  
            int i;  
            for(i=0;i<m-1;i++)  
            {  
                scanf("%d",&data);  
                pNode pNew = (pNode)malloc(sizeof(Node));  
                if(pNew == NULL)  
                    exit(EXIT_FAILURE);  
                pNew->data = data;  
                pNew->next = NULL;  
                pCur->next = pNew;  
                pCur = pCur->next;  
            }  
        }  
      
        pNode pHead2 = NULL;  
        if(n>0)  
        {  
            int data;  
            scanf("%d",&data);  
            pHead2 = (pNode)malloc(n*sizeof(Node));  
            if(pHead2 == NULL)  
                exit(EXIT_FAILURE);  
            pHead2->data = data;  
            pHead2->next = NULL;  
      
            pNode pCur = pHead2;  
            int i;  
            for(i=0;i<n-1;i++)  
            {  
                scanf("%d",&data);  
                pNode pNew = (pNode)malloc(sizeof(Node));  
                if(pNew == NULL)  
                    exit(EXIT_FAILURE);  
                pNew->data = data;  
                pNew->next = NULL;  
                pCur->next = pNew;  
                pCur = pCur->next;  
            }  
        }  
      
        pNode pResult = FindFirstCommonNode(pHead1,pHead2);  
        if(pResult != NULL)  
            printf("%d\n",pResult->data);  
        else  
            printf("My God\n");  
    }  
    return 0;  
}  

/**************************************************************
    Problem: 1505
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:70 ms
    Memory:5292 kb
****************************************************************/