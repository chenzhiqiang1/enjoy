#include<stack>
#include<stdio.h>
#include<queue>
#include<string>
#include <sstream>
#include<iostream>
using namespace std;

template <class Type>  
Type stringToNum(const string& str)  
{  
    istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
}

int main(){
	stack <int> s1,s2;
	int n;
	string s,temp;
	cin>>n;
	while(n+1){
		getline(cin,s);
		if((s.substr(0,4))=="PUSH"){
			int c=stringToNum<int>(s.substr(5));
			if(c<0)
				return -1;
			s1.push(c);
		}
		else if((s.substr(0,3))=="POP"){
			if(s1.empty()!=NULL && s2.empty()!=NULL)
				cout<<-1<<endl;
			else{
				if(!s2.empty()){
					cout<<s2.top()<<endl;
					s2.pop();
				}
				else{
					while(!s1.empty()){
						s2.push(s1.top());
						s1.pop();
					}
					cout<<s2.top()<<endl;
					s2.pop();
				}
			}
		}
		n--;
	}
	return 0;
}