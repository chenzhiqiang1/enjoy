#include<iostream>
#include<string>
using namespace std;

char get_day(string s1,string s2){
	unsigned i;
	for(i=0;i<s1.length();i++){
			if(s1[i]>='A' && s1[i]<='Z'&& s1[i]==s2[i]){
				return s1[i];
			}
	}
	return -1;
}

char get_hour(string s1,string s2){
	unsigned i,j;
	int count;
	count=0;
	for(i=0;i<s1.length();i++){
		if(s1[i]>='A' && s1[i]<='Z'&& s1[i]==s2[i]){
			count++;
			break;
		}
	}
	for(j=i+1;j<s1.length();j++){
		if(s1[j]==s2[j] && ((s1[j]>='A' && s1[j]<='Z') || (s1[j]>='0' && s1[j]<='9'))){
			return s1[j];
		}
	}
	return -1;
}

int get_min(string s1,string s2){
	unsigned i;
	for(i=0;i<s1.length();i++){
		if(s1[i]==s2[i] && ((s1[i]>='A' && s1[i]<='Z') || (s1[i]>'a' && s1[i]<='z') || (s1[i]>='0' && s1[i]<='9'))){
				return i;
		}
	}
	return -1;
}

int main(){
	string s[4];
	cin>>s[0]>>s[1]>>s[2]>>s[3];

	char ch1=get_day(s[0],s[1]);
	if(ch1==-1)
		cout<<"error"<<endl;
	switch(ch1){
        case 'A':
            cout<<"MON ";
            break;
        case 'B':
            cout<<"TUE ";
            break;
        case 'C':
            cout<<"WED ";
            break;
        case 'D':
            cout<<"THU ";
            break;
        case 'E':
            cout<<"FRI ";
            break;
        case 'F':
            cout<<"SAT ";
            break;
        case 'G':
            cout<<"SUN ";
    }

	char ch2=get_hour(s[0],s[1]);
	if(ch2==-1)
		cout<<"error"<<endl;
	if(ch2<='9')
		cout<<"0"<<ch2<<":";
	else cout<<ch2-'A'+10<<":";
	int temp=get_min(s[2],s[3]);
	if(temp==-1)
		cout<<"error"<<endl;
	if(temp<10)
		cout<<"0"<<temp<<endl;
	else cout<<temp<<endl;
	return 0;
}