/*
题目描述：
    小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

输入：
    输入有多组数据。
    每组数据仅包括1个整数S(S<=1,000,000)。如果S为负数时,则结束输入。

输出：
    对应每组数据,若不存在和为S的连续正数序列,则输出“Pity!”;否则,按照开始数字从小到大的顺序,输出所有和为S的连续正数序列。每组数据末尾以“#”号结束。

样例输入：
    4
    5
    100
    -1

样例输出：
    Pity!
    #
    2 3
    #
    9 10 11 12 13 14 15 16
    18 19 20 21 22
    #

大致思路如下（慢慢琢磨吧，不难理解，直接从论坛Copy过来的）：

S = ( a0 + aN)N/2 ---- 等差数列求和公式
   = ( 2a0-1 + N )N /2

==>  2a0 = 2S/N - N + 1
==>  2S % N == 0 && N < sqrt(2S)

for N =  [ 2 , sqrt(2S) )
      if 2S % N == 0 && 2a0 % 2 == 0
            show( a0 , N )
*/


#include<stdio.h>  
#include<math.h>  
bool can;  
      
/* 
打印从Start开始的连续n个正数序列 
*/  
void PrintSequence(int start ,int n)  
{  
    int i;  
    for(i=0;i<n;i++)  
    {  
        printf("%d",start+i);  
        if(i == n-1)  
            printf("\n");  
        else  
            printf(" ");  
    }  
}  
      
/* 
找到和为s的连续正数序列 
*/  
void FindSumSequence(int s)  
{  
    int i=(int)sqrt((double)(2*s));  
    //这里的i为要求的连续正数的个数，至少为2 

    for(i;i>=2;i--)  
    {  
        if((2*s)%i == 0)  
        {  
            int DoubleStart = 2*s/i-i+1;  
            if((DoubleStart&1) == 0)    //如果为偶数  
            {  
                can = true;  
                PrintSequence(DoubleStart/2,i);  
            }  
        }  
    }  
}  
      
int main()  
{  
    int s;  
    while(scanf("%d",&s) != EOF && s>=0)  
    {  
        can = false;  
        FindSumSequence(s);  
        if(!can)  
            printf("Pity!\n");  
        printf("#\n");  
    }  
    return 0;  
}

/**************************************************************
    Problem: 1354
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:110 ms
    Memory:928 kb
****************************************************************/