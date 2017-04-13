/*
��Ŀ������
    ��һ���ַ���(1<=�ַ�������<=10000��ȫ���ɴ�д��ĸ���)���ҵ���һ��ֻ����һ�ε��ַ���

���룺
    �����ж�������
    ÿһ������һ���ַ�����

�����
    �����һ��ֻ����һ�ε��ַ��±꣬û��ֻ����һ�ε��ַ������-1��

�������룺
    ABACCDEFF
    AA

���������
    1
    -1

    �����ַ������ظ����ߴ������ֵ����⣬��õľ��ǹ�ϣ�����ַ����е��ַ���Ϊkey���ַ����ִ�����Ϊvalue���ٶ�ֻ��ASCII�뷶Χ�ڵ��ַ�������Կ���һ��256��С��int���飬��ÿ���ַ���key��ӳ�䵽������Ķ�Ӧλ���ϣ�����ÿ�γ��ֵĴ������ɣ�����һ���ַ���������ÿ���ַ����ֵĴ�����������int����Ķ�Ӧλ���ϣ��ڶ��α����ַ���������һ�γ���ĳ���ַ��Զ�Ӧ���Ĺ�ϣ��Ķ�Ӧλ�ô���Ԫ��Ϊ1������ַ����ǵ�һ��ֻ����һ�ε��ַ�����������Ǳ�����ϣ��int���飩�����ҵ��Ĺ�ϣ���еĵ�һ��Ԫ��Ϊ1��λ�ö�Ӧ���ַ�Ϊ�ַ����е�һ����С��ֻ����һ�ε��ַ���ʱ�临�Ӷ�ΪO��n������Ҫ�����256��int�ռ������������Կ����ռ临�Ӷ�ΪO��1����
    ���⣬���Ҫʡ�ռ䣬���ǿ���bitmap�㷨��������λ����ʾ��Ӧ�ַ����ֵĴ���������0�Σ���Ϊ00������һ����Ϊ01������2�μ����ϣ���ά����10���ɡ�
    ���⣬��һ����Ҫע�⣬char�ķ�Χ��-128-127��unsigned char�ķ�Χ������0-255�����ASCIIֵ��128-255֮����ַ����������Ϊ��char�ͣ���ת��Ϊintֵ�ķ�Χ����-128--1֮�䣬���������Ĵ����������֡�
*/

#include<stdio.h>  
#include<string.h>  
      
/* 
���ص�һ������һ�ε��ַ� 
*/  
char FirstOnceChar(char *str)  
{  
    if(str == NULL)  
        return '\0';  
      
    int hashtable[256];  
    memset(hashtable,0,sizeof(hashtable));  
    char *pCur = str;  
    while(*pCur != '\0')  
    {  
        if(*pCur>=0)  
            hashtable[*(pCur++)]++;  
        else  
            hashtable[*(pCur++)+256]++;  
    }  
      
    while(*str != '\0')  
    {  
        int index;  
        if(*str>=0)  
            index = *str;  
        else  
            index = *str+256;  
      
        if(hashtable[index] == 1)  
            return *str;  
        else  
            str++;  
    }  
    return '\0';  
}  
      
/* 
���ص�һ������һ�ε��ַ����±� 
*/  
int IndexOfFirstOnceChar(char *str)  
{  
    if(str == NULL)  
        return -1;  
      
    int len = strlen(str);  
    int hashtable[256];  
    memset(hashtable,0,sizeof(hashtable));  
    int i;  
    for(i=0;i<len;i++)  
    {  
        if(str[i]>=0)  
            hashtable[str[i]]++;  
        else  
            hashtable[str[i]+256]++;  
    }  
      
    for(i=0;i<len;i++)  
    {  
        int index;  
        if(str[i]>=0)  
            index = str[i];  
        else  
            index = str[i]+256;  
      
        if(hashtable[index] == 1)  
            return i;  
    }  
    return -1;  
}  
      
int main()  
{  
    char str[10010];  
    while(gets(str) != NULL)  
        printf("%d\n",IndexOfFirstOnceChar(str));  
    return 0;  
}  

/**************************************************************

    Problem: 1283
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:10 ms
    Memory:912 kb
****************************************************************/