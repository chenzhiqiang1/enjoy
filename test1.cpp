/*
题目描述：
    输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

输入：
    输入可能包含多个测试样例。
    对于每个测试案例，输入的第一行为一个整数m (1<=m <=100)代表输入的正整数的个数。
    输入的第二行包括m个正整数，其中每个正整数不超过10000000。

输出：
    对应每个测试案例，
    输出m个数字能排成的最小数字。

样例输入：
    3
    23 13 6
    2
    23456 56

样例输出：
    13236
    2345656
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char strs[100][10];

/* 
自定义比较规则 
*/ 
int mycompare(const void *str1,const void *str2){
	static char s1[20];  
    static char s2[20];  
    char *string1 = (char *)str1;  
    char *string2 = (char *)str2;  
    //将两个字符串合并在一起  
    sprintf(s1,"%s%s",string1,string2);  
    sprintf(s2,"%s%s",string2,string1);  
  
    return strcmp(s1,s2);  
}

/* 
以字符串形式打印出最小的整数 
*/  
void PrintMinNum(int *nums,int len){
	if(nums==NULL || len<1)
		return ;
	int i;
	for(i=0;i<len;i++){
		sprintf(strs[i],"%d",nums[i]);
	}
	qsort(strs,len,10*sizeof(char),mycompare);
	for(i=0;i<len;i++)
		printf("%s",strs[i]);  
	printf("\n");
}

int main(){
	int nums[100];  
    int m;  
    while(scanf("%d",&m) != EOF)  
    {  
        int i;  
        for(i=0;i<m;i++)   
            scanf("%d",nums+i);  
        PrintMinNum(nums,m);  
    }  
    return 0;  
}

/**************************************************************
    Problem: 1504
    User: mmc_maodun
    Language: C++
    Result: Accepted
    Time:240 ms
    Memory:1020 kb
****************************************************************/