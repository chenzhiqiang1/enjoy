#include<stdio.h>  
#include<stdlib.h>  
#define N 100

typedef struct Node  
{  
    int data;  
    int index;  //�ڵ��ţ���1��ʼ���㣩  
    int pNext;  
    int pSibling;   //����ָ��  
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
            //����n+1���ڵ�ռ䣬�ճ�����һ���������ڵ��žʹ�1��ʼ  
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