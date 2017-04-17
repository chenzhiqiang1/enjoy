/*
��Ŀ������
    ����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��

���룺
    ÿ�����԰�������1�С�
    ����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��

�����
    ��Ӧÿ������,���ֵ�������������С�

�������룺
    abc
    BCA

���������
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

    ����������һ�����ϣ�����һ����Ŀ��ûAC��̫�ܴ���ˣ����ﵹ�����㷨�����⣬��Ҫ�Ǽ�Ҫ����������ַ������ֵ������У���Ҫȥ���ظ����ַ���������ֱ���ڲ����������ַ�����ǰ���£�ֱ�Ӱ���Ҫ������ַ�������������һ���ϣ����Ǿ��������ˣ���Ȼ��ʹ����ֱ�ӵķ������Կռ任ȡ����������е��ַ������浽һ���ַ��������У�����ȫ���к���ַ��������Ϊ9��=362880���ʿ���һ��362900����ַ�����������������Щ�ַ������������Щ�ַ�����������������ѡ������ͨ��strcpy�ַ����������򣬽����ȡ�������������������ʱ�����Σ������Ҫ��ϵͳ�Դ���qsort���ź��������AC�ˣ�˳��Ҳ��ϰ����qsort���÷����˽�ĸ�������Щ��
*/

#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
      
char result[362900][10];  
int count = 0; //�����ַ����ĸ���  
      
/* 
���������ַ� 
*/  
void swap(char *a,char *b)  
{  
    char temp = *a;  
    *a = *b;  
    *b = temp;  
}  
      
/* 
���ַ���str��begin��ʼ�ĺ�����ַ��������� 
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
��Permutation��װ���� 
*/  
void PermutationAllChar(char *str)  
{  
    if(str == NULL)  
        return ;  
    Permutation(str,0);  
}  
      
/* 
�Ƚ�str1��str2�Ĵ�С 
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
      
        //���Ŷ��ַ�����������ֵ�����  
        //֮ǰ����ѡ�����򣬲�ͨ�������ַ�������OJ�ϱ���ʱ  
        //���ÿ��ţ�AC��  
        qsort(result,count,10*sizeof(char),myCompare);  
      
        //�����ظ��ַ���  
        int i;  
        for(i=0;i<count;i++)  
        {  
            if(strcmp(result[i],result[i+1]) == 0)  
                continue;  
            puts(result[i]);  
        }  
       
        //��һ���ַ���������Ȼ��result����Ŀ�ʼ����ʼ���  
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