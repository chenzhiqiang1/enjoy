/*
题目描述：

    给定一棵树，同时给出树中的两个结点，求它们的最低公共祖先。

输入：

    输入可能包含多个测试样例。
    对于每个测试案例，输入的第一行为一个数n(0<n<1000)，代表测试样例的个数。
    其中每个测试样例包括两行，第一行为一个二叉树的先序遍历序列，其中左右子树若为空则用0代替，其中二叉树的结点个数node_num<10000。
    第二行为树中的两个结点的值m1与m2(0<m1,m2<10000)。

输出：

    对应每个测试案例，
    输出给定的树中两个结点的最低公共祖先结点的值，若两个给定结点无最低公共祖先，则输出“My God”。

样例输入：

    2
    1 2 4 6 0 0 7 0 0 5 8 0 0 9 0 0 3 0 0
    6 8
    1 2 4 6 0 0 7 0 0 5 8 0 0 9 0 0 3 0 0
    6 12

样例输出：

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
前序遍历找出根节点到数据域为val的节点路径，保存在path数组中, 
这里index是保存到path数组中的元素的下标，*len用来保存路径长度， 
如果能找到val，则返回ture，找不到则返回false 
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
获取两个路径的最后一个公共节点, 
由于对树的先序遍历的结果中，前面一定有些节点相同，因此一定能找到最后一个相同节点 
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
根据先序遍历序列创建二叉树，由于可能改变根节点的指向，因此传入BTNode的二级指针 
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
销毁二叉树 
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