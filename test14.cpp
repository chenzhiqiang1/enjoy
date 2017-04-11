/*
��Ŀ������
    ͳ��һ�����������������г��ֵĴ�����

���룺
    ÿ�����԰����������У�
    ��һ����1������n����ʾ����Ĵ�С��1<=n <= 10^6��
    �ڶ�����n����������ʾ����Ԫ�أ�ÿ��Ԫ�ؾ�Ϊint��
    ��������1������m����ʾ��������m�β�ѯ��1<=m<=10^3��
    ������m�У�ÿ����һ������k����ʾҪ��ѯ������

�����
    ��Ӧÿ�����԰�������m�������ÿ��1��������ʾ�����и����ֳ��ֵĴ�����

�������룺
    8
    1 2 3 3 3 3 4 5
    1
    3

���������
    4

    ��������⣬�����ö��ֲ����ҵ������֣������ٱ�����ǰ����ͬ�����֣�ͳ�ƴ���������������ƽ��ʱ�临�Ӷ�ΪO��logn����������ΪO(n),��ָoffer�ϸ���˼·�������ö��ֲ��ҷֱ��ҵ������ֵ�һ�κ����һ�γ��ֵ�λ�ã�������ʱ�临�Ӷ�ƽ���������O��logn��
*/

#include<stdio.h>  
#include<stdlib.h>  
      
/* 
���ֲ��ҷ�����key���ֵĴ��� 
*/  
int CountTimesInArrays(int *arr,int len,int key)  
{  
    if(arr==NULL || len<1)  
        return 0;  
      
    int start = 0;  
    int end = len-1;  
    int mid;  
    while(start <= end)  
    {  
        mid = (start+end)>>1;  
        if(arr[mid] == key)  
            break;  
        else if(arr[mid] > key)  
            end = mid-1;  
        else   
            start = mid+1;  
    }  
      
      
    //�����˳���0�ε����  
    int times = 0;  
    /*if(start <= end)  
    {  
        int i;  
        times = 1;  
        for(i=mid+1;i<=end;i++)  
            if(arr[i] == key)  
                times++;  
        for(i=mid-1;i>=start;i--)  
            if(arr[i] == key)  
                times++;  
    }*/  
	for(int i=start;i<=end;i++)
	{
		if(arr[i] == key)  
                times++;
	}
    return times;  
}   
      
int main()  
{  
    int n;  
    while(scanf("%d",&n) != EOF)  
    {  
        int *arr = (int *)malloc(n*sizeof(int));  
        if(arr == NULL)  
            exit(EXIT_FAILURE);  
      
        int i;  
        for(i=0;i<n;i++)  
            scanf("%d",arr+i);  
        int m;  
        scanf("%d",&m);  
        for(i=0;i<m;i++)  
        {  
            int k;  
            scanf("%d",&k);  
            printf("%d\n",CountTimesInArrays(arr,n,k));  
        }  
      
        free(arr);  
        arr = NULL;  
    }  
    return 0;  
} 

/**************************************************************
    Problem: 1349
    User: mmc_maodun
    Language: C++
    Result: Accepted
    Time:800 ms
    Memory:4928 kb
****************************************************************/