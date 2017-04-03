/*
题目描述：
    求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

输入：
    输入可能包含多个测试样例。
    对于每个测试案例，输入为一个整数n(1<= n<=100000)。

输出：
    对应每个测试案例，
    输出1+2+3+…+n的值。

样例输入：
    3
    5

样例输出：
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

