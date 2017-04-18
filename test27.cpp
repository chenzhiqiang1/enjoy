/*
题目描述：
    输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

输入：
    每个测试案例包括n+1行：
    第一行为2个整数n，k(1<=n<=10000)，n表示结点的个数，k表示要求的路径和，结点编号从1到n。                                                                                                       
    接下来有n行。这n行中每行为3个整数vi,leftnode,rightnode，vi表示第i个结点的值，leftnode表示第i个结点的左孩子结点编号，rightnode表示第i个结点的右孩子结点编号，若无结点值为-1。编号为1的结点为根结点。

输出：
   对应每个测试案例，先输出“result:”占一行，接下来按字典顺序输出满足条件的所有路径，这些路径由结点编号组成，输出格式参照输出样例。

样例输入：
    5 22
    10 2 3
    5 4 5
    12 -1 -1
    4 -1 -1
    7 -1 -1
    1 5
    1 -1 -1

样例输出：
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
    int index;  //节点的下标值(从1开始计算)  
    int lchild;  
    int rchild;  
}BTNode;  
      
//用数组result保存结果，参数top为最后一个元素的下标，  
//这里其实相当于是用数组模拟栈保存结果序列。  
BTNode result[100000];  
      
/* 
采用前序遍历的方式打印和为sum的序列 
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
      
    //根据题目要求，需要按照字典顺序输出，因此需要判断索引下标的大小  
    if(pTree[root].lchild < pTree[root].rchild)  
    {  
        //这里不需要再加判断语句，在下层递归中的入口处会判断  
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
