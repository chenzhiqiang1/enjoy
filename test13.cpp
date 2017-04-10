/*
��Ŀ������
    �����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ���������������һ���������ַ�����S���������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����

���룺
    ����������ݣ�ÿ���������ݰ���һ���ַ�����S�ͷǸ�����K������S�ĳ��Ȳ�����1000��

�����
    ��Ӧÿ�����԰�������������С�

�������룺
    UDBOJ 4
    abba 1

���������
    JUDBO
    bbaa

    �����֮ǰ��Cracking the Coding interview���������Ƶģ�һ�������η�ת�����ɵõ���ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��������ھŶ�OJ�ϲ��ԣ���ҪҪ�����ƶ���λ�������ַ�������ʱ�������ȡ�༴�ɡ�
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
��ת�ַ����д�start��end���ⲿ�� 
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
������kλ��õ����ַ� 
*/  
void ROLString(char *str,int k)  
{  
    if(str == NULL || k<=0)  
        return;  
          
    int len = strlen(str);  
    //Ҫ����k����len�����  
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