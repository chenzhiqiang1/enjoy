/*
题目描述：
    将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。

输入：
    输入可能包含多个测试样例。
    对于每个测试案例，输入为一个合法或者非法的字符串，代表一个整数n(1<= n<=10000000)。

输出：
    对应每个测试案例，
    若输入为一个合法的字符串(即代表一个整数)，则输出这个整数。
    若输入为一个非法的字符串，则输出“My God”。

样例输入：
    5
    -5
    +8

样例输出：
    5
    -5
    8

    关于这道题目，题目本身还是不错的，真正核心的代码也就那么两行，大部分代码基本都在做非法输入的检查。
*/

#include<stdio.h>  
bool IsValid;  
      
long StrToIInt(const char *str)  
{  
    //非法输入  
    if(str == NULL)  
    {  
        IsValid = false;  
        return 0;  
    }  
      
    //是否为负数  
    bool IsMinus = false;  
      
    //跳过前面的空白字符  
    while(*str == ' ')  
        str++;  
      
    //第一个非空白字符为+号  
    if(*str == '+')  
        str++;  
    //第一个非空白字符为-号  
    else if(*str == '-')  
    {  
        str++;  
        IsMinus = true;  
    }  
      
    //如果只输入了空白字符、符号位，或者什么都没输入，也为非法输入  
    if(*str == '\0')  
    {  
        IsValid = false;  
        return 0;  
    }  
      
      
    //后面的输入如果合法，则转化为整数  
    long num = 0;   //转化为整数后的结果  
    //这样可以使类似234asd的输入也判定为合法输入，得到的结果为234  
    while(*str != '\0')  
    {  
        //输入不在0-9之间，属于非法输入  
        if(*str<'0' || *str>'9')  
        {  
            IsValid = false;  
            return 0;  
        }  
        //对不包含符号位的合法输入进行转换  
        num = 10*num + (*str - '0');  
        str++;  
    }  
          
    //根据符号位转换正负  
    num = IsMinus ? (-1*num) : num;  
    //判断是否溢出了int的范围  
    if(num>0X7FFFFFFF || num<(signed int)0X80000000)  
    {  
        IsValid = false;  
        return 0;  
    }  
      
    //上面没有返回，则说明合法并没有发生溢出  
    return num;  
}  
      
int main()  
{  
    static char str[100000000];  
    while(gets(str) != NULL)  
    {  
        IsValid = true;  
        long result = StrToIInt(str);  
        if(IsValid)  
            printf("%ld\n",result);  
        else  
            printf("My God\n");  
    }  
    return 0;  
}  