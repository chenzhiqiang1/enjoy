/*
��ָoffer�ϵ���չ��Ŀ������һ���ַ�����������ַ������ַ���������ϣ����������ַ�����abc�����a��b��c��ab��ac��bc��abc��
    ˼·������һ�����ƣ�Ҳ�����õݹ���⡣���Կ����󳤶�Ϊn���ַ�����m���ַ�����ϣ���ΪC(n,m)��ԭ����Ľ⼴ΪC(n, 1), C(n, 2),...C(n, n)���ܺ͡�������C(n, m)���ӵ�һ���ַ���ʼɨ�裬ÿ���ַ������������Ҫô��ѡ�У�Ҫô����ѡ�У������ѡ�У��ݹ����C(n-1, m-1)�����δ��ѡ�У��ݹ����C(n-1, m)���������ַ�ʽ��n��ֵ������٣��ݹ����ֹ����n=0��m=0��
*/

#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
using namespace std;

//��ͷɨ���ַ����õ���һ���ַ�����Ե�һ���ַ���������ѡ��
//������ַ��ŵ������ȥ��������������Ҫ��ʣ�µ�n-1���ַ���ѡȡm-1���ַ���
//�����������ַ��ŵ������ȥ������Ҫ��ʣ�µ�n-1���ַ���ѡȡm���ַ� 

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
        printf("��%d�����\t",num++);

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