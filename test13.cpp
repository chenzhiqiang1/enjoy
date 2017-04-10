/*
题目描述：
    汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

输入：
    多组测试数据，每个测试数据包含一个字符序列S和非负整数K。其中S的长度不超过1000。

输出：
    对应每个测试案例，输出新序列。

样例输入：
    UDBOJ 4
    abba 1

样例输出：
    JUDBO
    bbaa

    这道题之前在Cracking the Coding interview上做过类似的，一样的三次反转，即可得到，时间复杂度为O(n)，空间复杂度为O(1)。这道题在九度OJ上测试，主要要考虑移动的位数大于字符串长度时的情况，取余即可。
*/

#include<stdio.h>  
#include<string.h>  
      
void Swap(char *a,char *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
      
/* 
翻转字符串中从start到end的这部分 
*/  
void ReverseString(char *str,int start,int end)  
{  
    while(start < end)  
    {  
        Swap(&str[start],&str[end]);  
        start++;  
        end--;  
    }  
}  
      
/* 
求左旋k位后得到的字符 
*/  
void ROLString(char *str,int k)  
{  
    if(str == NULL || k<=0)  
        return;  
          
    int len = strlen(str);  
    //要考虑k大于len的情况  
    k = k%len;  
    if(k == 0)  
        return;  
      
    ReverseString(str,0,k-1);  
    ReverseString(str,k,len-1);  
    ReverseString(str,0,len-1);  
}  
      
int main()  
{  
    char str[1010];  
    int k;  
    while(scanf("%s %d",str,&k) != EOF)  
    {  
        ROLString(str,k);  
        puts(str);  
    }  
    return 0;  
}  

/**************************************************************
    Problem: 1362
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:60 ms
    Memory:912 kb
****************************************************************/