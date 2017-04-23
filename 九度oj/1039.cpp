/*
题目描述：
    You are given a sequence of integer numbers. Zero-complexity transposition of the sequence is the reverse of this sequence. Your task is to write a program that prints zero-complexity transposition of the given sequence.

输入：
    For each case, the first line of the input file contains one integer n-length of the sequence (0 ＜ n ≤ 10 000). The second line contains n integers numbers-a1, a2, …, an (-1 000 000 000 000 000 ≤ ai ≤ 1 000 000 000 000 000).

输出：
    For each case, on the first line of the output file print the sequence in the reverse order.

样例输入：
    5
    -3 4 6 -8 9

样例输出：
    9 -8 6 4 -3
*/

#include<stdio.h>  
#define MAX_SIZE 10000
int main(){
	int m,i;
	long long buff[MAX_SIZE];
	while(scanf("%d",&m)!=EOF){
		for(i=0;i<m;i++) scanf("%lld",&buff[i]);
		for(i=m-1;i>0;i--) printf("%lld ",buff[i]);
		printf("%lld\n",buff[i]);
	}
	return 0;
}

//#include<stdio.h>
//int main()
//{
//    int i,n;
//    long long a[1000];
//    while(scanf("%d",&n)!=EOF){
//        for(i=0;i<n;i++) scanf("%lld",&a[i]);
//        for(i=n-1;i>0;i--) printf("%lld ",a[i]);
//        printf("%lld\n",a[0]);                       
//    }
//    return 0;
//}
