/*
题目描述：
    输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。

输入：
    每个测试案例包括2行：
    第一行为2个整数n，k(1<=n，k<=200000)，表示数组的长度。
    第二行包含n个整数，表示这n个数，数组中的数的范围是[0,1000 000 000]。

输出
    对应每个测试案例，输出最小的k个数，并按从小到大顺序打印。

样例输入：
    8 4
    4 5 1 6 2 7 3 8

样例输出：
    1 2 3 4

	可以考虑采用小顶堆，将数组的n个元素建成一个小顶堆，这样最小的元素就位于堆顶，将它与数组的最后一个元素交换，这样最小的元素就保存在了数组的最后一个位置，而后同样利用堆排序的思想，调整前面的n-1个元素，使之再次构成一个小顶堆，这样k次调整后，最小的k个元素便保存在了数组的最后k个位置，而且是从右向左依次增大。
    这种方法，建立小顶堆需要O(n)的时间，而后筛选出k个最小的数需要对堆调整k次，每次调整所需时间依次为O(logn)、O(log(n-1))、O(log(n-2))...O(log(n-k))，可以近似认为每次调整需要的时间为O(logn)。这样，该方法的时间复杂度为O(n+klogn)，至于空间复杂度，如果可以改变输入的数组，我们可以直接在数组上建堆和调整堆，这是空间复杂度为O(1)，如果不能改变输入数组的话，我们就要建立一个小顶堆，这样空间复杂度为O(n)。
*/

#include<stdio.h>  
#include<stdlib.h>  
      
/* 
arr[start+1...end]满足小顶堆的定义， 
将arr[start]加入到小顶堆arr[start+1...end]中， 
调整arr[start]的位置，使arr[start...end]也成为小顶堆 
注：由于数组从0开始计算序号，也就是二叉堆的根节点序号为0， 
因此序号为i的左右子节点的序号分别为2i+1和2i+2 
*/  
void HeapAdjustDown(int *arr,int start,int end)  
{  
    int temp = arr[start];  //保存当前节点  
    int i = 2*start+1;      //该节点的左孩子在数组中的位置序号  
    while(i<=end)  
    {  
        //找出左右孩子中最小的那个  
        if(i+1<=end && arr[i+1]<arr[i])    
            i++;  
        //如果符合堆的定义，则不用调整位置  
        if(arr[i]>=temp)   
            break;  
        //最小的子节点向上移动，替换掉其父节点  
        arr[start] = arr[i];  
        start = i;  
        i = 2*start+1;  
    }  
    arr[start] = temp;  
}  
      
/* 
得到最小的k个数，保存在arr中的最后面k个位置 
*/  
void MinHeapKNum(int *arr,int len,int k)  
{  
    if(arr==NULL || len<1 || k<1 || k>len)  
        return;  
      
    int i;  
    //把数组建成为小顶堆  
    //第一个非叶子节点的位置序号为(len-1)/2  
    for(i=(len-1)/2;i>=0;i--)  
        HeapAdjustDown(arr,i,len-1); 
	for(i=0;i<len;i++) printf("%d ",arr[i]);
	printf("\n");
    //进行堆排序  
    for(i=len-1;i>=len-k;i--)  
    {  
        //堆顶元素和最后一个元素交换位置，  
        //这样最后的一个位置保存的是最小的数，  
        //每次循环依次将次小的数值在放进其前面一个位置，  
        int temp = arr[i];  
        arr[i] = arr[0];  
        arr[0] = temp;  
        //将arr[0...i-1]重新调整为小顶堆  
        HeapAdjustDown(arr,0,i-1);  
    }  
}  
      
      
int main()  
{  
    int n,k;  
    while(scanf("%d %d",&n,&k) != EOF)  
    {  
        int *A = (int *)malloc(sizeof(int)*n);  
        if(A == NULL)  
            exit(EXIT_FAILURE);  
      
        int i;  
        for(i=0;i<n;i++)  
            scanf("%d",A+i);  
      
        MinHeapKNum(A,n,k);  
        for(i=n-1;i>=n-k;i--)  
        {  
            //根据要求的格式输出  
            if(i == n-k)  
                printf("%d\n",A[i]);  
            else  
                printf("%d ",A[i]);  
        }  
    }  
    return 0;  
}  

/**************************************************************
    Problem: 1371
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:840 ms
    Memory:8752 kb
****************************************************************/