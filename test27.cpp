/*
��Ŀ������
    ����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����

���룺
    ÿ�����԰�������n+1�У�
    ��һ��Ϊ2������n��k(1<=n<=10000)��n��ʾ���ĸ�����k��ʾҪ���·���ͣ�����Ŵ�1��n��                                                                                                       
    ��������n�С���n����ÿ��Ϊ3������vi,leftnode,rightnode��vi��ʾ��i������ֵ��leftnode��ʾ��i���������ӽ���ţ�rightnode��ʾ��i�������Һ��ӽ���ţ����޽��ֵΪ-1�����Ϊ1�Ľ��Ϊ����㡣

�����
   ��Ӧÿ�����԰������������result:��ռһ�У����������ֵ�˳�������������������·������Щ·���ɽ������ɣ������ʽ�������������

�������룺
    5 22
    10 2 3
    5 4 5
    12 -1 -1
    4 -1 -1
    7 -1 -1
    1 5
    1 -1 -1

���������
    result:
    A path is found: 1 2 5
    A path is found: 1 3
    result:
*/

#include<stdio.h>  
#include<stdlib.h>  
      
typedef struct BTNode  
{  
    int data;  
    int index;  //�ڵ���±�ֵ(��1��ʼ����)  
    int lchild;  
    int rchild;  
}BTNode;  
      
//������result������������topΪ���һ��Ԫ�ص��±꣬  
//������ʵ�൱����������ģ��ջ���������С�  
BTNode result[100000];  
      
/* 
����ǰ������ķ�ʽ��ӡ��Ϊsum������ 
*/  
void PrintFindPath(BTNode *pTree,int root,int exp,int top)  
{  
    if(pTree==NULL|| root==-1)  
        return;  
      
    result[top] = pTree[root];  
    if(pTree[root].lchild==-1 && pTree[root].rchild==-1)  
    {  
        int sum = 0;  
        int i;  
        for(i=0;i<=top;i++)  
            sum += result[i].data;  
        if(sum == exp)  
        {  
            printf("A path is found:");  
            for(i=0;i<=top;i++)  
                printf(" %d",result[i].index);  
            printf("\n");  
        }  
    }  
      
    //������ĿҪ����Ҫ�����ֵ�˳������������Ҫ�ж������±�Ĵ�С  
    if(pTree[root].lchild < pTree[root].rchild)  
    {  
        //���ﲻ��Ҫ�ټ��ж���䣬���²�ݹ��е���ڴ����ж�  
        PrintFindPath(pTree,pTree[root].lchild,exp,top+1);  
        PrintFindPath(pTree,pTree[root].rchild,exp,top+1);  
    }  
    else  
    {  
        PrintFindPath(pTree,pTree[root].rchild,exp,top+1);  
        PrintFindPath(pTree,pTree[root].lchild,exp,top+1);  
    }  
}  
      
int main()  
{  
    int n,k;  
    while(scanf("%d %d",&n,&k) != EOF)  
    {  
        BTNode *pTree = NULL;  
        if(n>0)  
        {  
            pTree = (BTNode *)malloc(n*sizeof(BTNode));  
            if(pTree == NULL)  
                exit(EXIT_FAILURE);  
      
            int i;  
            for(i=0;i<n;i++)  
            {  
                int vi,leftnode,rightnode;  
                scanf("%d %d %d",&vi,&leftnode,&rightnode);  
                pTree[i].data = vi;  
                pTree[i].index = i+1;  
                if(leftnode != -1)  
                    pTree[i].lchild = leftnode-1;  
                else  
                    pTree[i].lchild = -1;  
                if(rightnode != -1)  
                    pTree[i].rchild = rightnode-1;  
                else  
                    pTree[i].rchild = -1;  
            }  
        }  
      
        printf("result:\n");  
        PrintFindPath(pTree,0,k,0);  
        free(pTree);  
    }  
    return 0;  
}  
/**************************************************************
    Problem: 1368
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:30 ms
    Memory:2636 kb
****************************************************************/
