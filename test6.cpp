/*
��Ŀ������
    ÿ����һ��ͯ��,JOBDU����׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�HF��ΪJOBDU������Ԫ��,��ȻҲ׼����һЩС��Ϸ������,�и���Ϸ��������:����,��С������Χ��һ����Ȧ��Ȼ��,�����ָ��һ����m,�ñ��Ϊ1��С���ѿ�ʼ������ÿ�κ���m���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,���Ҳ��ٻص�Ȧ��,��������һ��С���ѿ�ʼ,����1...m����....������ȥ....ֱ��ʣ�����һ��С����,���Բ��ñ���,�����õ�JOBDU����ġ�����̽���ϡ���ذ�(��������Ŷ!!^_^)��������������,�ĸ�С���ѻ�õ������Ʒ�أ�

���룺
    �����ж������ݡ�
    ÿ������һ��,����2������n(0<=n<=1,000,000),m(1<=m<=1,000,000),n,m�ֱ��ʾС���ѵ�����(���1....n-1,n)��HFָ�����Ǹ���m(����������)�����n=0,��������롣

�����
    ��Ӧÿ������,�������õ��󽱵�С���ѱ�š�

�������룺
    1 10
    8 5
    6 6
    0

���������
    1
    3
    4
*/
#include<stdio.h>  
      
typedef struct Node  
{  
    int next;   //��һ��Ԫ�صı��  
    int num;    //��ţ���1��ʼ  
}Node;  
      
Node arr[1000000];  
      
int FindLastRemaining(int n,int m)  
{  
    if(n<1 || m<1)  
        return 0;  
      
    int start = 1;  
    int current = start;  
    int pre = current;  
    while(start != arr[start].next)  
    {  
        //�ҵ���ɾԪ�غ�����ǰһ��Ԫ��  
        int i;  
        for(i=0;i<m-1;i++)  
        {  
            pre = current;  
            current = arr[current].next;  
        }  
              
        //ɾ��Ԫ�أ����½�������  
        arr[pre].next = arr[current].next;  
        start = arr[pre].next;  
        current = start;  
    }  
    return arr[start].num;  
}  
      
int main()  
{  
    int n;  
    while(scanf("%d",&n) != EOF && n != 0)  
    {  
        int m;  
        scanf("%d",&m);  
      
        //���������ɻ�  
        int i;  
        for(i=1;i<=n;i++)  
        {  
            arr[i].num = i;  
            if(i == n)  
                arr[i].next = 1;  
            else  
                arr[i].next = i+1;  
        }  
      
        printf("%d\n",FindLastRemaining(n,m));  
    }  
    return 0;  
}  


/**************************************************************
    Problem: 1356
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:290 ms
    Memory:912 kb
****************************************************************/
//#include<stdio.h>  
//      
//int LastRemaining(int n,int m)  
//{  
//    if(n<1 || m<1)  
//        return 0;  
//      
//    int last = 0;  
//    int i;  
//    for(i=2;i<=n;i++)  
//        last = (last + m)%i;  
//    return last;  
//}  
//      
//int main()  
//{  
//    int n;  
//    while(scanf("%d",&n) != EOF && n != 0)  
//    {  
//        int m;  
//        scanf("%d",&m);  
//        printf("%d\n",LastRemaining(n,m)+1);  
//    }  
//    return 0;  
//}  

