/*
题目描述
已知一颗二叉树的中序遍历序列和后序遍历序列，求二叉树的深度。

输入
输入数据有多组，输入T，代表有T组数据。每组数据包括两个长度小于50的字符串，第一个字符串表示二叉树的中序遍历，第二个表示二叉树的后序遍历。

输出
输出二叉树的深度。

示例输入
2
dbgeafc
dgebfca
lnixu
linux

示例输出
4
3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *lchild,*rchild;
};
int search(char a[],char c)
{
    int k,i;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==c)
        {
            k=i;
            return k;
            break;
        }
    }
    if(a[i]=='\0') k=-1;
    return 0;
}
struct node *creattree(char a[],char b[],int n)
{
   int k;
   struct node *t;
   if(n==0)    t=NULL;
   else
   {
       k=search(a,b[n-1]);
       if(k==-1) t=NULL;
       else
       {
           t=(struct node *)malloc(sizeof(struct node));
           t->data=b[n-1];
           if(k==0) t->lchild=NULL;
           else t->lchild=creattree(a,b,k);
           if(k==n-1) t->rchild=NULL;
           else t->rchild=creattree(a+k+1,b+k,n-k-1);
       }

   }
   return t;
}
/*void Depth(struct node *t,int level,int *depth)
{
    if(t)
    {
        if(level>*depth)
            *depth=level;
        Depth(t->lchild,level+1,depth);
        Depth(t->rchild,level+1,depth);
    }
}*/
int deep(struct node *root)
{
    int ld,rd;
    if(!root)
    {
        return 0;
    }
    else
    {
        ld=deep(root->lchild);
        rd=deep(root->rchild);
        if(ld>rd)
        return ld+1;
        else return rd+1;
    }
}
int main()
{
   int t,n;
   char a[100],b[100];
   scanf("%d",&t);
   while(t--)
   {
       // int level=1,depth=0;
       struct node *t;
       scanf("%s%s",a,b);
       n=strlen(a);
       t=creattree(a,b,n);
       //Depth(t,level,&depth);
       printf("%d\n",deep(t));
    }
    return 0;
}
