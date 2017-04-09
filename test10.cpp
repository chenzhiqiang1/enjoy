/*
��Ŀ������
    ��ֻ��������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ���Ϊ����������7��
    ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������

���룺
    �������һ������N(1<=N<=1500)��

�����
    �����ж���������ݣ�����ÿ�����ݣ�
    �����N��������

�������룺
    3

���������
    3

˼·����򵥵ķ���������ͨ����һ�������ϳ���2��3��5���ж������ǲ��ǳ����������ڴ�1��ʼ�����������ж�ÿ�����ǲ��ǳ����������³����ĸ���������������ĸ���Ϊ����ֵʱ��������Ҫ��ĵ�n�����������ַ�����ʱ�临�Ӷ�ΪO��k���������kΪ��n�������Ĵ�С�������1500�������Ĵ�СΪ859963392����ô����Ҫ�ж�859963392�Σ�ʱ��Ч�ʷǳ��͡�
      ֱ�۵��Ż���ʩ���ǿ��ܲ��ܽ�ʱ�临�ӶȽ��͵�O��n������ֻ�ڳ����ϻ�ʱ�䣬�����ڷǳ������˷�ʱ�䡣��ָoffer�ϸ���˼·�ܺã���O��n���ĸ����ռ����õ�O(n)��ʱ�临�Ӷȡ������˼���ǣ�ÿһ��������Ȼ����֮ǰ��ĳ��������2��3��5�ĳ˻��õ��ģ�������һ����������֮ǰ�ĳ����ֱ����2��3��5���ҳ�����������С�Ĳ��Ҵ��ڵ�ǰ��������ֵ����Ϊ��һ��Ҫ��ĳ�����
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
    int CurrentIndex= 1;    //��ǰҪ��ĳ������±�����  
    int *p2 = UglyNums;  
    int *p3 = UglyNums;  
    int *p5 = UglyNums;  
      
    //��ÿ������������������  
    while(CurrentIndex < index)  
    {  
        int min = Min(2*(*p2),3*(*p3),5*(*p5));  
        UglyNums[CurrentIndex] = min;  
              
        //ÿ��ѭ�������ϴε�p2,p3��p5����һ��λ�ÿ�ʼ  
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