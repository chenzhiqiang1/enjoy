/*
题目描述：
    在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

输入：
    每个测试案例包括两行：
    第一行包含一个整数n，表示数组中的元素个数。其中1 <= n <= 10^5。
    第二行包含n个整数，每个数组均为int类型。

输出：
    对应每个测试案例，输出一个整数，表示数组中的逆序对的总数。

样例输入：
    4
    7 5 6 4

样例输出：
    5

思路：最简单的方法是顺序数组，将每个数字与后面的比较，统计逆序对的个数，这种方法的时间复杂度为O(n*n)，这种方法写出的代码在九度OJ上测试，会超时。剑指offer给出了归并排序的思路，这个有点难想到啊，也可能是我太弱了，根本没往这方面想！理解了思路，就不难了，将数组划分成两个子数组，再将子数组分别划分成两个子数组，统计每个子数组内的逆序对个数，并将其归并排序，再统计两个子数组之间的逆序对个数，并进行归并排序。这就是归并排序的变种，在归并排序代码的基础上稍作改进即可。
      合理还要注意一点：全局变量count不能声明为int型，必须为long long型。因为题目中说数组最大为10^5，那么最大逆序对为(10^5-1)*10^5/2，这个数大约在50亿左右，超过了int型的表示范围。
*/

#include<stdio.h>  
#include<stdlib.h>  
      
/* 
统计两个子数组之间的逆序对 
*/  
long long MergePairsBetweenArray(int *arr,int *brr,int start,int mid,int end)  
{  
    int i = mid;  
    int j = end;  
    int k = end;  //辅助数组的最后一位  
    long long count = 0;  
      
    //设置两个指针i,j分别从右往左依次比较，  
    //将较大的依次放入辅助数组的右边  
    while(i>=start && j>=mid+1)  
    {  
        if(arr[i] > arr[j])  
        {  
            count += j-mid;  
            brr[k--] = arr[i--];  
        }  
        else  
            brr[k--] = arr[j--];  
    }  
      
    //将其中一个数组中还剩下的元素拷贝到辅助数组中，  
    //两个循环只会执行其中的一个  
    while(i>=start)  
        brr[k--] = arr[i--];  
    while(j>=mid+1)  
        brr[k--] = arr[j--];  
      
    //从辅助数组中将元素拷贝到原数组中，使其有序排列  
    for(i=end;i>k;i--)  
        arr[i] = brr[i];  
      
    return count;  
}  
      
/* 
统计数组中的所有的逆序对 
*/  
long long CountMergePairs(int *arr,int *brr,int start,int end)  
{  
    long long PairsNum = 0;  
    if(start<end)  
    {  
        int mid = (start+end)>>1;  
        PairsNum += CountMergePairs(arr,brr,start,mid); //统计左边子数组的逆序对  
        PairsNum += CountMergePairs(arr,brr,mid+1,end); //统计右边子数组的逆序对  
        PairsNum += MergePairsBetweenArray(arr,brr,start,mid,end); //统计左右子数组间的逆序对  
    }  
    return PairsNum;  
}  
      
/* 
将函数封装起来 
*/  
long long CountTotalPairs(int *arr,int len)  
{  
    if(arr==NULL || len<2)  
        return 0;  
      
    int *brr = (int *)malloc(len*sizeof(int));  
    if(brr == NULL)  
        exit(EXIT_FAILURE);  
      
    long long sum = CountMergePairs(arr,brr,0,len-1);  
    free(brr);  
    brr = NULL;  
      
    return sum;  
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
      
        printf("%lld\n",CountTotalPairs(arr,n));  
      
        free(arr);  
        arr = NULL;  
    }  
    return 0;  
}  

/**************************************************************
    Problem: 1348
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:100 ms
    Memory:1696 kb
****************************************************************/