/*
��Ŀ������
    HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ������JOBDU�����鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý��������,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����᲻�ᱻ������ס��

���룺
    �����ж�������,ÿ��������ݰ������С�
    ��һ��Ϊһ������n(0<=n<=100000),��n=0ʱ,�������������ȥ��һ�а���n������(���Ǳ�֤������������[-1000,1000])��

�����
    ��Ӧÿ�����԰���,��Ҫ���3����������һ��,�ֱ��ʾ���������������͡����������ĵ�һ��Ԫ�ص��±�����һ��Ԫ�ص��±ꡣ���Ǵ��ڶ��������,�������ʼԪ���±���С���Ǹ���

�������룺
    3
    -1 -3 -2
    5
    -8 3 2 0 5
    8
    6 -3 -2 7 -15 1 2 2
    0

���������
    -1 0 0
    10 1 4
    8 0 3

    ǰ����ר��д��һƪ���������������������£������http://blog.csdn.net/ns_code/article/details/20942045������ĵ�����������Ҫ�������м��и�����������������²��ܵõ���ȷ�Ľ����������Ĳ�����������ȫ�����������ˣ��������������Щϸ���ϵĲ�ͬ�������������Ҫ����������������ĺͣ���Ҫ�����������������飬���Ҫ������������������������������ʼ�ͽ�����λ�á�
*/

#include<stdio.h>  
#include<stdlib.h>   
bool flag;  
      
int MaxSubSum(int *arr,int len,int *indexBegin,int *indexEnd)  
{  
    if(arr==NULL || len<1)  
    {  
        flag = false;  
        return -1;  
    }  
      
    int i;  
    int MaxSum;  
    int CurSum;  
    int CurBegin; //��ǰ��CurSum�Ŀ�ʼ��������  
    int CurEnd;  //��ǰ��CurSum�Ľ�����������  
    for(i=0;i<len;i++)  
    {  
        if(i == 0)  
        {  
            //���õ�һ��Ԫ�س�ʼ��  
            *indexBegin = 0;  
            *indexEnd = 0;  
            CurBegin = 0;  
            CurEnd = 0;  
            MaxSum = arr[i];  
            CurSum = arr[i];  
        }  
        else  
        {  
            //ǰ��ĺ�С��0������ǰ��ĺͣ��ӵ�ǰԪ�����¿�ʼ����  
            if(CurSum < 0)  
            {  
                CurSum = arr[i];  
                CurBegin = i;  
                CurEnd = i;  
            }  
            else  
            {  
                CurSum += arr[i];  
                CurEnd = i;  
            }  
            if(CurSum > MaxSum)  
            {  
                MaxSum = CurSum;  
                //�����ǰ�ʹ���ǰ����ֵ����ͣ�  
                //���滻�����͵Ŀ�ʼ�����ͽ�������  
                *indexBegin = CurBegin;  
                *indexEnd = CurEnd;  
            }  
        }  
    }  
    return MaxSum;  
}  
      
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF && n!=0)  
    {  
        int *arr = (int *)malloc(sizeof(int)*n);  
        if(arr == NULL)  
            exit(EXIT_FAILURE);  
      
        int i;  
        for(i=0;i<n;i++)  
            scanf("%d",arr+i);  
      
        flag = true;  
        int indexBegin,indexEnd;  
        int result = MaxSubSum(arr,n,&indexBegin,&indexEnd);      
        if(flag)  
        {  
            printf("%d ",result);  
            printf("%d ",indexBegin);  
            printf("%d\n",indexEnd);  
        }  
      
        free(arr);  
        arr = NULL;  
    }  
    return 0;  
}  
/**************************************************************
    Problem: 1372
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:450 ms
    Memory:1304 kb
****************************************************************/