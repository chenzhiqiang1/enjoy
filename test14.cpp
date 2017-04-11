/*
题目描述：
    统计一个数字在排序数组中出现的次数。

输入：
    每个测试案例包括两行：
    第一行有1个整数n，表示数组的大小。1<=n <= 10^6。
    第二行有n个整数，表示数组元素，每个元素均为int。
    第三行有1个整数m，表示接下来有m次查询。1<=m<=10^3。
    下面有m行，每行有一个整数k，表示要查询的数。

输出：
    对应每个测试案例，有m行输出，每行1整数，表示数组中该数字出现的次数。

样例输入：
    8
    1 2 3 3 3 3 4 5
    1
    3

样例输出：
    4

    我做这道题，是先用二分查找找到该数字，而后再遍历其前后相同的数字，统计次数。这种做法的平均时间复杂度为O（logn），最坏情况下为O(n),剑指offer上给的思路是两次用二分查找分别找到该数字第一次和最后一次出现的位置，这样的时间复杂度平均和最坏都是O（logn）
*/

#include<stdio.h>  
#include<stdlib.h>  
      
/* 
二分查找法计算key出现的次数 
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
      
      
    //包含了出现0次的情况  
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