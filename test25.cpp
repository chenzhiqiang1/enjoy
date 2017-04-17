/*
题目描述：
    输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

输入：
    每个测试案例包括1行。
    输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

输出：
    对应每组数据,按字典序输出所有排列。

样例输入：
    abc
    BCA

样例输出：
    abc
    acb
    bac
    bca
    cab
    cba

    ABC
    ACB
    BAC
    BCA
    CAB
    CBA

    昨晚折腾了一个晚上，连这一道题目都没AC，太受打击了！这里倒不是算法的问题，主要是既要考虑输出的字符串按字典序排列，又要去掉重复的字符串。本想直接在不保存所有字符串的前提下，直接按照要求输出字符串，但折腾了一晚上，还是决定放弃了，依然是使用最直接的方法，以空间换取结果，将所有的字符串保存到一个字符串数组中，由于全排列后的字符串数最大为9！=362880，故开辟一个362900大的字符串数组用来保存这些字符串，而后对这些字符串进行排序，先用了选择排序，通过strcpy字符串进行排序，结果争取，但第三组测试用例超时，无奈，最后还是要用系统自带的qsort快排函数，这次AC了，顺带也复习了下qsort的用法，了解的更深入了些！
*/

#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
      
char result[362900][10];  
int count = 0; //排列字符串的个数  
      
/* 
交换两个字符 
*/  
void swap(char *a,char *b)  
{  
    char temp = *a;  
    *a = *b;  
    *b = temp;  
}  
      
/* 
对字符串str从begin开始的后面的字符进行排列 
*/  
void Permutation(char *str,int begin)  
{  
    int len = strlen(str);  
    if(begin == len-1)  
    {  
        strcpy(result[count++],str);  
        return;  
    }  
      
    int i;  
    for(i=begin;i<len;i++)  
    {  
        swap(&str[begin],&str[i]);  
        Permutation(str,begin+1);  
        swap(&str[begin],&str[i]);  
    }  
}  
      
/* 
将Permutation封装起来 
*/  
void PermutationAllChar(char *str)  
{  
    if(str == NULL)  
        return ;  
    Permutation(str,0);  
}  
      
/* 
比较str1和str2的大小 
*/  
int myCompare(const void *a,const void *b)  
{  
    char *s1 = (char *)a;  
    char *s2 = (char *)b;  
    return strcmp(s1,s2);  
}  
      
int main()  
{  
    char str[10];  
    while(gets(str))  
    {  
        PermutationAllChar(str);  
      
        //快排对字符串数组进行字典排序  
        //之前采用选择排序，并通过复制字符串排序，OJ上报超时  
        //改用快排，AC。  
        qsort(result,count,10*sizeof(char),myCompare);  
      
        //跳过重复字符串  
        int i;  
        for(i=0;i<count;i++)  
        {  
            if(strcmp(result[i],result[i+1]) == 0)  
                continue;  
            puts(result[i]);  
        }  
       
        //下一个字符的排列依然从result数组的开始处开始存放  
        count = 0;  
    }  
    return 0;  
}  

/**************************************************************
    Problem: 1369
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:220 ms
    Memory:8000 kb
****************************************************************/