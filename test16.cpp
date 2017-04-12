/*
题目：输入一个二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

剑指offer上给的第二种思路，用后序遍历真的是将递归发挥的淋漓尽致，先遍历节点的左右子树，左右子树都平衡才来判断该节点是否平衡，如果左右子树中有不平衡的，则直接返回false，避免了从上往下逐个节点地计算深度带来的重复遍历节点。
*/

#include<stdio.h>  
#include<stdlib.h>  
      
typedef struct BTNode  
{  
    char data;  
    struct BTNode *pLchild;  
    struct BTNode *pRchild;  
}BTNode, *BTree;  
      
BTree create_tree();  
bool IsBalanced(BTree,int *);  
bool IsBalanced(BTree);  
      
int main()  
{  
    BTree pTree = create_tree();  
    if(IsBalanced(pTree))  
        printf("Balanced\n");  
    else  
        printf("Not Balanced\n");  
      
    return 0;  
}  
      
BTree create_tree()  
{  
    BTree pA = (BTree)malloc(sizeof(BTNode));  
    BTree pB = (BTree)malloc(sizeof(BTNode));  
    BTree pD = (BTree)malloc(sizeof(BTNode));  
    BTree pE = (BTree)malloc(sizeof(BTNode));  
    BTree pC = (BTree)malloc(sizeof(BTNode));  
    BTree pF = (BTree)malloc(sizeof(BTNode));  
      
      
    pA->data = 'A';  
    pB->data = 'B';  
    pD->data = 'D';  
    pE->data = 'E';  
    pC->data = 'C';  
    pF->data = 'F';  
          
    pA->pLchild = pB;  
    pA->pRchild = pC;  
    pB->pLchild = pD;  
    pB->pRchild = pE;  
    pD->pLchild = NULL;  
    pD->pRchild = NULL;  
    pE->pLchild = pE->pRchild = NULL;  
    pC->pLchild = NULL;  
    pC->pRchild = pF;  
    pF->pLchild = pF->pRchild = NULL;   
          
    return pA;  
}  
      
      
/* 
后续递归遍历判断二叉树是否平衡 
*/  
bool IsBalanced(BTree pTree,int *depth)  
{  
    if(pTree == NULL)  
    {  
        *depth = 0;  
        return true;  
    }  
      
    int leftDepth,rightDepth;  
    if(IsBalanced(pTree->pLchild,&leftDepth) && IsBalanced(pTree->pRchild,&rightDepth))  
    {  
        int diff = leftDepth-rightDepth;  
        if(diff<=1 && diff>=-1)  
        {  
            *depth = (leftDepth>rightDepth ? leftDepth:rightDepth) + 1;  
            return true;  
        }  
    }  
    return false;  
}  
      
/* 
封装起来 
*/  
bool IsBalanced(BTree pTree)  
{  
    int depth = 0;  
    return IsBalanced(pTree,&depth);  
}  