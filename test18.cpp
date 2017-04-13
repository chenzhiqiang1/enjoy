/*
题目描述：
    在一个字符串(1<=字符串长度<=10000，全部由大写字母组成)中找到第一个只出现一次的字符。

输入：
    输入有多组数据
    每一组输入一个字符串。

输出：
    输出第一个只出现一次的字符下标，没有只出现一次的字符则输出-1。

样例输入：
    ABACCDEFF
    AA

样例输出：
    1
    -1

    处理字符串中重复或者次数出现等问题，最常用的就是哈希表，用字符串中的字符作为key，字符出现次数作为value，假定只有ASCII码范围内的字符，则可以开辟一个256大小的int数组，将每个字符（key）映射到该数组的对应位置上，计算每次出现的次数即可，遍历一次字符串，计算每个字符出现的次数，保存在int数组的对应位置上，第二次遍历字符串，若第一次出现某个字符对对应到的哈希表的对应位置处的元素为1，则该字符便是第一个只出现一次的字符，如果我们是遍历哈希表（int数组），则找到的哈希表中的第一个元素为1的位置对应的字符为字符串中第一个最小的只出现一次的字符。时间复杂度为O（n），需要额外的256个int空间来辅助，可以看做空间复杂度为O（1）。
    另外，如果要省空间，我们可以bitmap算法，用两个位来表示对应字符出现的次数，出现0次，则为00，出现一次则为01，出现2次及以上，都维持在10即可。
    另外，有一点需要注意，char的范围在-128-127，unsigned char的范围才是在0-255，因此ASCII值在128-255之间的字符，如果保存为了char型，其转化为int值的范围是在-128--1之间，这点在下面的代码中有体现。
*/

#include<stdio.h>  
#include<string.h>  
      
/* 
返回第一个出现一次的字符 
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
返回第一个出现一次的字符的下标 
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