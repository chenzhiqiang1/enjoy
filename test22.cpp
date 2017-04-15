/*
��Ŀ������
    ����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

���룺
    ������ܰ����������������
    ����ÿ�����԰���������ĵ�һ��Ϊһ����n(0<n<1000)��������������ĸ�����
    ��������n�У�ÿ��Ϊһ������������������������У���������������Ϊ������0���档

�����
    ��Ӧÿ�����԰�����
    ���������������ת���������˫������󣬴�����ͷ������β�ı��������

�������룺
    1
    2 1 0 0 3 0 0

���������
    1 2 3

    ˼·�������Ŀ�ؼ����ڲ��ܴ����µĽڵ㣬�粻Ȼ�����ǿ���ֱ�ӽ���������������������浽һ�������У������ٽ���һ��˫�����������ݱ��浽˫�������
    ���ﲻ�ܴ����½ڵ㣬����ֻ�ܸı�ڵ��ָ�����������Ľڵ㣬�����Ϊָ����������е�ǰ��ڵ㣬����������ͬ���õ��������������������Ŀ��Ȼ����������ı��֣�����ݹ鹹��ʵ�ּ��ɣ�ÿ�εݹ鶼����һ��ָ���ѹ���õ�˫�������β�ڵ��ָ�룬��������һ���ڵ�����������
    ���⣬�����OJ�������ʽ��ǰ��Ĳ�ͬ�������������û��˵�������������β�AC��ǰ���ζ��Ǳ�PE��˫����������һ��Ԫ�ص��������һ����Ҫ�и��ո���С�
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
������ĿҪ��ĸ�ʽ�������������� 
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
������������ķ�ʽ��������ת��Ϊ˫������ 
*pLasָ��˫����������һ���ڵ� 
*/  
void ConvertNode(BSTree pRoot,BSTree *pLast)  
{  
    if(pRoot == NULL)  
        return;  
          
    //��ת��������  
    if(pRoot->left != NULL)  
        ConvertNode(pRoot->left,pLast);  
      
    //��˫����������һ���ڵ�����ڵ�������һ��  
    pRoot->left = *pLast;  
    if(*pLast != NULL)  
        (*pLast)->right = pRoot;  
    *pLast = pRoot;  
      
    //ת��������  
    if(pRoot->right != NULL)  
        ConvertNode(pRoot->right,pLast);  
}  
      
/* 
����˫�������ͷ��� 
*/  
BSTree Convert(BSTree pRoot)  
{  
    if(pRoot == NULL)  
        return NULL;  
    if(pRoot->left==NULL && pRoot->right==NULL)  
        return pRoot;  
      
    BSTree pLast = NULL;  
    ConvertNode(pRoot,&pLast);  
          
    //����ͷ���  
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