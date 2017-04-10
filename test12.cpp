/*
题目描述：
    JOBDU最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

输入：
    每个测试案例为一行，表示一句英文句子。
    我们保证一个句子的单词数不会超过600，每个单词的长度也不会超过30。但是需要注意的是Fish是个不拘小节的人，有时候两个单词中间可能会有很多空格。为了方便起见，你可以认为一行的字符总数不会超过50000个，标点符号可以和普通字母一样处理。

输出：
    对应每个测试案例，把翻转后的正确的句子单独输出一行。

样例输入：
    student. a am I
    I'm a Freshman and I like JOBDU!

样例输出：
    I am a student.
    JOBDU! like I and Freshman a I'm

    先翻转整个字符串，再翻转每个单词。
*/

#include<stdio.h>  
      
void Swap(char *a,char *b)  
{  
    char temp = *a;  
    *a = *b;  
    *b = temp;  
}  
      
/* 
反转字符串 
*/  
void Reverse(char *str,char *begin,char *end)  
{  
    if(str==NULL || begin==NULL || end==NULL)  
        return;  
      
    while(begin < end)  
    {  
        Swap(begin,end);  
        begin++;  
        end--;  
    }  
}  
      
/* 
反转单词顺序 
*/  
void ReverseSentence(char *str)  
{  
    if(str == NULL)  
        return;  
      
    char *begin = str;  
    char *end = str;  
    while(*end != '\0')  
        end++;  
    end--;  
    //反转整个字符串  
    Reverse(str,begin,end);  
      
    //反转每个单词  
    begin = str;  
    while(*begin == ' ')  
        begin++;  
    end = begin;  
    while(*begin != '\0')  
    {  
        while(*end!=' ' && *end!='\0')  
            end++;  
        end--;  
        Reverse(str,begin,end);  
      
        //跳过多个空格  
        end++;  
        while(*end == ' ')  
            end++;  
        begin = end;  
    }  
}  
      
int main()  
{  
    char str[50000];  
    while(gets(str) != NULL)  
    {  
        ReverseSentence(str);  
        puts(str);  
    }  
    return 0;  
}  

/**************************************************************
    Problem: 1361
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:50 ms
    Memory:912 kb
****************************************************************/