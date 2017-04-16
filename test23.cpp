/*
剑指offer上解决八皇后问题，没有用传统的递归或非递归回溯法，而是用了很巧妙的全排列法。
    先说下八皇后问题：在8 X 8的国际象棋上摆放八个皇后，使其不能相互攻击，即任意两个皇后不得处于同一行，同一列或者同意对角线上，求出所有符合条件的摆法。
    全排列解决八皇后问题的思路如下：
    由于8个皇后不能处在同一行，那么肯定每个皇后占据一行，这样可以定义一个数组A[8]，数组中第i个数字，即A[i]表示位于第i行的皇后的列号。先把数组A[8]分别用0-7初始化，接下来对该数组做全排列，由于我们用0-7这7个不同的数字初始化数组，因此任意两个皇后肯定也不同列，那么我们只需要判断每个排列对应的8个皇后中是否有任意两个在同一对角线上即可，即对于数组的两个下标i和j，如果i-j==A[i]-A[j]或i-j==A[j]-A[i]，则认为有两个元素位于了同一个对角线上，则该排列不符合条件。
*/

#include<stdio.h>  
      
void swap(int *a,int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
      
/* 
如果有符合条件的摆法，打印出所有的摆法，否则，什么也不打印 
*/  
void CubVertex(int *A,int len,int begin)  
{  
    if(A==NULL || len!=8)  
        return;  
      
    if(begin == len-1)  
    {  
        int i,j;  
        bool can = true;    //是否又符合条件的摆法  
        for(i=0;i<len;i++)  
            for(j=i+1;j<len;j++)  
                if(i-j==A[i]-A[j] || i-j==A[j]-A[i])  
                {  
                    //如果任意两个在一条对角线上，则不符合  
                    can = false;  
                    break;  
                }  
        //有符合的摆法，就打印出来  
        if(can)  
        {  
            for(i=0;i<len;i++)  
                printf("%d ",A[i]);  
            printf("\n");  
        }  
    }  
    else  
    {  
        int i;  
        for(i=begin;i<len;i++)  
        {  
            swap(&A[begin],&A[i]);  
			for(int j=0;j<len;j++)  
                printf("%d ",A[j]);  
            printf("\n");  
            CubVertex(A,len,begin+1);  
            swap(&A[begin],&A[i]); 
			
        }  
    }  
}  
      
int main()  
{  
    int A[8] = {0,1,2,3,4,5,6,7};  
    CubVertex(A,8,0);  
    return 0;  
}  