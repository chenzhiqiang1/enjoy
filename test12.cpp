/*
��Ŀ������
    JOBDU�������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼�����磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��

���룺
    ÿ�����԰���Ϊһ�У���ʾһ��Ӣ�ľ��ӡ�
    ���Ǳ�֤һ�����ӵĵ��������ᳬ��600��ÿ�����ʵĳ���Ҳ���ᳬ��30��������Ҫע�����Fish�Ǹ�����С�ڵ��ˣ���ʱ�����������м���ܻ��кܶ�ո�Ϊ�˷���������������Ϊһ�е��ַ��������ᳬ��50000���������ſ��Ժ���ͨ��ĸһ������

�����
    ��Ӧÿ�����԰������ѷ�ת�����ȷ�ľ��ӵ������һ�С�

�������룺
    student. a am I
    I'm a Freshman and I like JOBDU!

���������
    I am a student.
    JOBDU! like I and Freshman a I'm

    �ȷ�ת�����ַ������ٷ�תÿ�����ʡ�
*/

#include<stdio.h>  
      
void Swap(char *a,char *b)  
{  
    char temp = *a;  
    *a = *b;  
    *b = temp;  
}  
      
/* 
��ת�ַ��� 
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
��ת����˳�� 
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
    //��ת�����ַ���  
    Reverse(str,begin,end);  
      
    //��תÿ������  
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
      
        //��������ո�  
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