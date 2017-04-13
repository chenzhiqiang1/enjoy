/*
题目：输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”。
    这里主要要分析两个方面：
    1、如何判断那些字符是需要删除的字符。同很多字符串问题一样，可以开辟一个哈希数组，全部初始化为false，将第二个字符串中字符对应的映射位置置为ture，表示这些位置对应的字符在第一个字符串中需要删除。
    2、关于删除字符的操作，每次删除一个，而后把后面的元素均左移一位，由于要删除的字符可能有多个，这种方法的时间复杂度为O（n*n）。我们这里有O（n）的删除方法，我们可以设想，当一个字符需要被删除的时候，我们把它所占的位置让它后面的字符来填补，也就相当于这个字符被删除了。在具体实现中，我们可以定义两个指针(pFast和pSlow)，初始的时候都指向第一字符的起始位置。当pFast指向的字符是需要删除的字符，则pFast直接跳过，指向下一个字符。如果pFast指向的字符是不需要删除的字符，那么把pFast指向的字符赋值给pSlow指向的字符，并且pFast和pStart同时向后移动指向下一个字符。这样，前面被pFast跳过的字符相当于被删除了。用这种方法，整个删除在O(n)时间内就可以完成。
    前面也有篇删除重复字符的博文用到了该删除方法，见这里：http://blog.csdn.net/ns_code/article/details/21328151。
    另外，有一点需要注意，char的范围在-128-127，unsigned char的范围才是在0-255，因此ASCII值在128-255之间的字符，如果保存为了char型，其转化为int值的范围是在-128--1之间，这点在下面的代码中有体现。
*/

#include<stdio.h>  
#include<string.h>  
#define MAX 256  
      
void DeleteChars(char *str1,char *str2)  
{  
    if(str1==NULL || str2==NULL)  
        return;  
      
    bool hashtable[MAX];  
    memset(hashtable,0,sizeof(hashtable));  
      
    //将str2中字符对应的hashtable数组中的位置上的值设为ture  
    while(*str2 != '\0')  
    {  
        //ASCII值在128-255之间的的字符，  
        //用char保存，转化为int型,在-128--1之间  
        int index;  
        if(*str2 >= 0)  
            index = *str2;  
        else  
            index = *str2 + 256;  
      
        hashtable[index] = true;  
        ++str2;  
    }  
      
    char *pFast = str1;  
    char *pSlow = str1;  
    while(*pFast != '\0')  
    {  
        int index;  
        if(*pFast >= 0)  
            index = *pFast;  
        else  
            index = *pFast + 256;  
      
        //无论是否碰到要删除的字符，pFast都后移，  
        //只有没碰到要删除的字符时，pSlow才后移  
        if(!hashtable[index])  
            *pSlow++ = *pFast;    
        ++pFast;  
    }  
    *pSlow = '\0';  
}  
      
int main()  
{  
      
    char str1[] = "They are students";  
    char str2[] = "Tdentt";  
    DeleteChars(str1,str2);  
    puts(str1);  
    return 0;  
}  