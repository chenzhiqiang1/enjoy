#include<stdio.h>  
#include<stdlib.h>  
#define N 100

typedef struct Node  
{  
    int data;  
    int index;  //节点编号（从1开始计算）  
    int pNext;  
    int pSibling;   //特殊指针  
}Node;  

void myprint(Node *node,int n){
	for(int i=1;i<n+1;i++){
		printf("%d%2d\n",node[i].index,node[i].pSibling);
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!= EOF){
		Node *pHead=NULL;
		if(n>0)  
        {  
            //开辟n+1各节点空间，空出来第一个，这样节点编号就从1开始  
            pHead = (Node *)malloc((n+1)*sizeof(Node));  
            if(pHead == NULL)  
                exit(EXIT_FAILURE);  
            int i,data;  
            for(i=1;i<n+1;i++)  
            {  
                scanf("%d",&data);  
                pHead[i].data = data;  
                pHead[i].index = i;  
                if(i == n)  
                    pHead[i].pNext = NULL;  
                else  
                    pHead[i].pNext = i+1;  
                pHead[i].pSibling = 0;  
            }  
  
            int ti;  
            for(i=1;i<n+1;i++)  
            {  
                scanf("%d",&ti);  
                pHead[i].pSibling = ti;  
            }  
        }  
		myprint(pHead,n);
	}
}