/*
题目描述：
    把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。
    习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

输入：
    输入包括一个整数N(1<=N<=1500)。

输出：
    可能有多组测试数据，对于每组数据，
    输出第N个丑数。

样例输入：
    3

样例输出：
    3

思路：最简单的方法就是先通过将一个数不断除以2，3，5来判定该数是不是丑数，而后在从1开始，依次往后判断每个数是不是丑数，并记下丑数的个数，这样当计算的个数为给定值时，便是需要求的第n个丑数，这种方法的时间复杂度为O（k），这里的k为第n个丑数的大小，比如第1500个丑数的大小为859963392，那么就需要判断859963392次，时间效率非常低。
      直观的优化措施就是看能不能将时间复杂度降低到O（n），即只在丑数上花时间，而不在非丑数上浪费时间。剑指offer上给的思路很好，用O（n）的辅助空间来得到O(n)的时间复杂度。其核心思想是：每一个丑数必然是由之前的某个丑数与2，3或5的乘积得到的，这样下一个丑数就用之前的丑数分别乘以2，3，5，找出这三这种最小的并且大于当前最大丑数的值，即为下一个要求的丑数。
*/

#include<stdio.h>  
#include<stdlib.h>  
      
int UglyNums[1500];  
      
int Min(int a,int b,int c)  
{  
    int min =(a<b)?a:b;  
    min = (min<c)?min:c;  
    return min;  
}  
      
int GetUglyNum(int index)  
{  
    if(index <= 0)  
        return 0;  
      
    UglyNums[0] = 1;  
    int CurrentIndex= 1;    //当前要求的丑数的下标索引  
    int *p2 = UglyNums;  
    int *p3 = UglyNums;  
    int *p5 = UglyNums;  
      
    //求每个丑数，并保存起来  
    while(CurrentIndex < index)  
    {  
        int min = Min(2*(*p2),3*(*p3),5*(*p5));  
        UglyNums[CurrentIndex] = min;  
              
        //每次循环都从上次的p2,p3和p5的下一个位置开始  
        while(2*(*p2) <= UglyNums[CurrentIndex])  
            ++p2;  
        while(3*(*p3) <= UglyNums[CurrentIndex])  
            ++p3;  
        while(5*(*p5) <= UglyNums[CurrentIndex])  
            ++p5;  
      
        ++CurrentIndex;  
    }  
      
    int result = UglyNums[index-1];  
    return result;  
}  
      
int main()  
{  
    int n;  
    while(scanf("%d",&n) != EOF)  
        printf("%d\n",GetUglyNum(n));  
    return 0;     
}  
/**************************************************************
    Problem: 1214
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:20 ms
    Memory:920 kb
****************************************************************/