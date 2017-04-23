#include<iostream>
#include<string>
using namespace std;
int main(){
	int i=0;
	string a;
	getline(cin,a);
	int len=a.length();
	while(i<len){
		if(a[i]==' ') cout<<"%20";
		else cout<<a[i];
		i++;
	}
	cout<<endl;
}