#include<string>
#include<math.h>
#include<iostream>  
using namespace std;  

int main(){
	long long int a,b;
	int result,c;
	cin>>a>>b>>c;
	if(a >= -5*10^8 && a <= b && b <= 5*10^8 && c>=1 && c<=1000){
		result=0;
		for(long long int i=a;i<=b;i++){
			if(i%c==0){
				result=(b-i)/c+1;
				break;
			}
		}
		cout<<result<<endl;
	}
	return 0;
}

//#include<iostream>
//using namespace std;
//int main(){
//	int a,b,c;
//	cin>>a>>b>>c;
//	int t= b/c - a/c;
//	if (a<=0 && b >= 0) t++;
//	cout<<t;
//	return 0;
//}

