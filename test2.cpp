/*
��Ŀ������

    ����һ������ͬʱ�������е�������㣬�����ǵ���͹������ȡ�

���룺

    ������ܰ����������������
    ����ÿ�����԰���������ĵ�һ��Ϊһ����n(0<n<1000)��������������ĸ�����
    ����ÿ�����������������У���һ��Ϊһ��������������������У���������������Ϊ������0���棬���ж������Ľ�����node_num<10000��
    �ڶ���Ϊ���е���������ֵm1��m2(0<m1,m2<10000)��

�����

    ��Ӧÿ�����԰�����
    �����������������������͹������Ƚ���ֵ�������������������͹������ȣ��������My God����

�������룺

    2
    1 2 4 6 0 0 7 0 0 5 8 0 0 9 0 0 3 0 0
    6 8
    1 2 4 6 0 0 7 0 0 5 8 0 0 9 0 0 3 0 0
    6 12

���������

    2
    My God
*/

/**************************************************************
    Problem: 1509
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:130 ms
    Memory:920 kb
****************************************************************/

#include<stdio.h>  
#include<stdlib.h>  
      
typedef struct BTNode  
{  
    struct BTNode *lchild;  
    struct BTNode *rchild;  
    int data;  
}BTNode,*BTree;  
      
/* 
ǰ������ҳ����ڵ㵽������Ϊval�Ľڵ�·����������path������, 
����index�Ǳ��浽path�����е�Ԫ�ص��±꣬*len��������·�����ȣ� 
������ҵ�val���򷵻�ture���Ҳ����򷵻�false 
*/ 
bool GetPreTraversePath(BTree pTree,int val,int *path,int index,int *len)  
{  
    if(pTree == NULL)  
    {  
        *len = 0;  
        return false;  
    }  
      
    path[index] = pTree->data;  
    if(pTree->data == val)  
    {  
        *len = index+1;  
        return true;  
    }  
    else  
    {  
        bool can;  
        can = GetPreTraversePath(pTree->lchild,val,path,index+1,len);  
        if(!can)  
            can = GetPreTraversePath(pTree->rchild,val,path,index+1,len);  
        return can;  
    }  
}  
      
/* 
��ȡ����·�������һ�������ڵ�, 
���ڶ�������������Ľ���У�ǰ��һ����Щ�ڵ���ͬ�����һ�����ҵ����һ����ͬ�ڵ� 
*/  
int GetFirstCommonNode(int *path1,int len1,int *path2,int len2)  
{  
    int shortLen = len1<len2 ? len1:len2;  
    int i;  
    for(i=0;i<shortLen;i++)  
    {  
        if(path1[i] != path2[i])  
            break;  
    }  
    return path1[i-1];  
}  
      
/* 
��������������д��������������ڿ��ܸı���ڵ��ָ����˴���BTNode�Ķ���ָ�� 
*/  
void CreateBTree(BTree *pRoot)  
{  
    int data;  
    scanf("%d",&data);  
    if(data == 0)  
        *pRoot = NULL;  
    else  
    {  
        *pRoot = (BTree)malloc(sizeof(BTNode));  
        if(*pRoot == NULL)  
            exit(EXIT_FAILURE);   
        (*pRoot)->data = data;  
        (*pRoot)->lchild = NULL;  
        (*pRoot)->rchild = NULL;  
        CreateBTree(&((*pRoot)->lchild));  
        CreateBTree(&((*pRoot)->rchild));  
    }  
}  
      
/* 
���ٶ����� 
*/  
void DestroyBTree(BTree pRoot)  
{  
    if(pRoot != NULL)  
    {  
        if(pRoot->lchild != NULL)  
            DestroyBTree(pRoot->lchild);  
        if(pRoot->rchild != NULL)  
            DestroyBTree(pRoot->rchild);  
        free(pRoot);  
        pRoot = NULL;  
    }  
}  
      
      
int main()  
{  
    int path1[10000];  
    int path2[10000];  
      
    int n;  
    while(scanf("%d",&n) != EOF)  
    {  
        int i;  
        for(i=0;i<n;i++)  
        {  
            BTree pRoot = NULL;  
            CreateBTree(&pRoot);  
      
            int val1,val2;  
            scanf("%d %d",&val1,&val2);  
      
            int len1,len2;  
            bool can1 = GetPreTraversePath(pRoot,val1,path1,0,&len1);  
            bool can2 = GetPreTraversePath(pRoot,val2,path2,0,&len2);  
      
            if(can1 && can2)  
                printf("%d\n",GetFirstCommonNode(path1,len1,path2,len2));  
            else  
                printf("My God\n");  
      
            DestroyBTree(pRoot);  
        }  
    }  
    return 0;  
}  