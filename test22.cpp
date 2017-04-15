/*
题目描述：
    输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

输入：
    输入可能包含多个测试样例。
    对于每个测试案例，输入的第一行为一个数n(0<n<1000)，代表测试样例的个数。
    接下来的n行，每行为一个二叉搜索树的先序遍历序列，其中左右子树若为空则用0代替。

输出：
    对应每个测试案例，
    输出将二叉搜索树转换成排序的双向链表后，从链表头至链表尾的遍历结果。

样例输入：
    1
    2 1 0 0 3 0 0

样例输出：
    1 2 3

    思路：这道题目关键在于不能创建新的节点，如不然，我们可以直接将二叉排序树中序遍历保存到一个数组中，而后再建立一个双性链表，将数据保存到双向链表里。
    这里不能创建新节点，我们只能改变节点的指向左右子树的节点，让其变为指向二叉链表中的前后节点，很明显这里同样用的是中序遍历，因此这道题目依然是中序遍历的变种，中序递归构造实现即可，每次递归都保存一个指向已构造好的双向链表的尾节点的指针，将其与下一个节点连接起来。
    另外，这道题OJ的输出格式与前面的不同，输出样例中又没有说明，我试了三次才AC，前两次都是报PE，双向链表的最后一个元素的输出后面一样，要有个空格才行。
*/

#include<stdio.h>  
#include<stdlib.h>  
      
typedef struct BSTNode  
{  
    int data;  
    struct BSTNode *left;  
    struct BSTNode *right;  
}BSTNode,*BSTree;  
      
/* 
根据题目要求的格式创建二叉排序树 
*/  
void CreateBST(BSTree *pRoot)  
{  
    int data;  
    scanf("%d",&data);  
    if(data == 0)  
        pRoot = NULL;  
    else  
    {  
        *pRoot = (BSTree)malloc(sizeof(BSTNode));  
        if(*pRoot == NULL)  
            exit(EXIT_FAILURE);  
        (*pRoot)->data = data;  
        (*pRoot)->left = NULL;  
        (*pRoot)->right = NULL;  
        CreateBST(&((*pRoot)->left));  
        CreateBST(&((*pRoot)->right));  
    }  
}  
      
/* 
采用中序遍历的方式将二叉树转化为双向链表， 
*pLas指向双向链表的最后一个节点 
*/  
void ConvertNode(BSTree pRoot,BSTree *pLast)  
{  
    if(pRoot == NULL)  
        return;  
          
    //先转化左子树  
    if(pRoot->left != NULL)  
        ConvertNode(pRoot->left,pLast);  
      
    //将双向链表的最后一个节点与根节点连接在一起  
    pRoot->left = *pLast;  
    if(*pLast != NULL)  
        (*pLast)->right = pRoot;  
    *pLast = pRoot;  
      
    //转换右子树  
    if(pRoot->right != NULL)  
        ConvertNode(pRoot->right,pLast);  
}  
      
/* 
返回双向链表的头结点 
*/  
BSTree Convert(BSTree pRoot)  
{  
    if(pRoot == NULL)  
        return NULL;  
    if(pRoot->left==NULL && pRoot->right==NULL)  
        return pRoot;  
      
    BSTree pLast = NULL;  
    ConvertNode(pRoot,&pLast);  
          
    //返回头结点  
    BSTree pHead = pLast;  
    while(pHead->left != NULL)  
        pHead = pHead->left;  
      
    return pHead;  
}  
      
int main()  
{  
    int n;  
    while(scanf("%d",&n) != EOF)  
    {  
        int i;  
        for(i=0;i<n;i++)  
        {  
            BSTree pRoot = NULL;  
            CreateBST(&pRoot);  
            BSTree pHead = Convert(pRoot);  
            while(pHead != NULL)  
            {  
                printf("%d ",pHead->data);  
                pHead = pHead->right;  
            }  
      
            printf("\n");  
            free(pRoot);  
            pRoot = NULL;  
        }  
    }  
    return 0;  
}  

/**************************************************************
    Problem: 1503
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:70 ms
    Memory:1704 kb
****************************************************************/