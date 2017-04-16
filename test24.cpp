/*
剑指offer上的拓展题目，输入一个字符串，输出该字符串的字符的所有组合，比如输入字符串：abc，输出a、b、c、ab、ac、bc、abc。
    思路：与上一题类似，也可以用递归求解。可以考虑求长度为n的字符串中m个字符的组合，设为C(n,m)。原问题的解即为C(n, 1), C(n, 2),...C(n, n)的总和。对于求C(n, m)，从第一个字符开始扫描，每个字符有两种情况，要么被选中，要么不被选中，如果被选中，递归求解C(n-1, m-1)。如果未被选中，递归求解C(n-1, m)。不管哪种方式，n的值都会减少，递归的终止条件n=0或m=0。
*/

#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
using namespace std;

//从头扫描字符串得到第一个字符，针对第一个字符，有两种选择
//把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选取m-1个字符；
//如果不把这个字符放到组合中去，则需要在剩下的n-1个字符中选取m个字符 

void Combination(char *string ,int number,vector<char> &result);

void Combination(char *string)
{
    assert(string != NULL);
    vector<char> result;
    int i , length = strlen(string);
    for(i = 1 ; i <= length ; ++i)
        Combination(string , i ,result);
}

void Combination(char *string ,int number , vector<char> &result)
{
    assert(string != NULL);
    if(number == 0)
    {
        static int num = 1;
        printf("第%d个组合\t",num++);

        vector<char>::iterator iter = result.begin();
        for( ; iter != result.end() ; ++iter)
            printf("%c",*iter);
        printf("\n");
        return ;
    }
    if(*string == '\0')
        return ;
    result.push_back(*string);
    Combination(string + 1 , number - 1 , result);
    result.pop_back();
    Combination(string + 1 , number , result);
}

int main(void)
{
    char str[] = "abc";
    Combination(str);
    return 0;
}