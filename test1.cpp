/*
��Ŀ������
    ����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��

���룺
    ������ܰ����������������
    ����ÿ�����԰���������ĵ�һ��Ϊһ������m (1<=m <=100)����������������ĸ�����
    ����ĵڶ��а���m��������������ÿ��������������10000000��

�����
    ��Ӧÿ�����԰�����
    ���m���������ųɵ���С���֡�

�������룺
    3
    23 13 6
    2
    23456 56

���������
    13236
    2345656
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char strs[100][10];

/* 
�Զ���ȽϹ��� 
*/ 
int mycompare(const void *str1,const void *str2){
	static char s1[20];  
    static char s2[20];  
    char *string1 = (char *)str1;  
    char *string2 = (char *)str2;  
    //�������ַ����ϲ���һ��  
    sprintf(s1,"%s%s",string1,string2);  
    sprintf(s2,"%s%s",string2,string1);  
  
    return strcmp(s1,s2);  
}

/* 
���ַ�����ʽ��ӡ����С������ 
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