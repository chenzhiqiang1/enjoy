/*
��Ŀ������
    ��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

���룺
    ������ܰ����������������
    ����ÿ�����԰���������Ϊһ������n(1<= n<=100000)��

�����
    ��Ӧÿ�����԰�����
    ���1+2+3+��+n��ֵ��

�������룺
    3
    5

���������
    6
    15
*/

#include <stdio.h>
int dfs(int n){
	int s=0;
	n&&(s=n+dfs(n-1));
	return s;
}

int main(){
	printf("%d\n",dfs(8));
	return 0;
}

//#include <iostream>
//using namespace std;
//
//class Gauss
//{
//	static int idx;
//	static int sum;
//  public:
//	Gauss()
//	{
//		idx++;
//		sum += idx;
//	}
//	void say(void)
//	{
//		cout<<"Count = "<<idx<<", Sum = "<<sum<<endl;
//	}
//};
//
//int Gauss::idx = 0;
//int Gauss::sum = 0;
//
//int main(void)
//{
//	Gauss * p = new Gauss[8];
//	p->say();
//	delete [] p;
//	return 0;
//}

