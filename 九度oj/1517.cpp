#include<stdio.h>  
#include<stdlib.h>  
      
typedef struct Link  
{  
    int data;  
    struct Link *next;  
}Node;  
      
int main()  
{  
    int n,k;  
    while(scanf("%d %d",&n,&k) != EOF)  
    {  
        if(n == 0)  
            printf("NULL\n");  
        else  
        {  
            int count = 1;  
            //构建链表   
            Node *head,*p,*s;  
            head = (Node *)malloc(sizeof(Node));  
            scanf("%d",&head->data);  
            head->next = NULL;  
            p = head;  
            for(int i = 1; i < n; i++)  
            {  
                s = (Node *)malloc(sizeof(Node));  
                scanf("%d",&s->data);  
                p->next = s;  
                p = s;  
            }         
            p->next = NULL;  
            //得到倒数第K个  
            p = head;  
            while(p != NULL)  
            {  
                if(count == n + 1 - k)  
                {  
                    printf("%d\n",p->data);  
                    break;  
                }  
                p = p->next;   
                count++;  
            }   
            if(count > n)  
                printf("NULL\n");  
        }  
    }  
}  