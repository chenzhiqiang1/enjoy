#include<iostream>
#include<string>
using namespace std;

//牛客网上通过，但是vs上数组扩容问题为解决
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int i,j,len;
        int count=0;
        len=strlen(str);
        if(len==NULL)
            return;
        for(i=0;i<=len;i++){
            if(str[i]==' ')
                count++;
        }
        int newlen=len+2*count+1;
        for(j=len+1;j>=0;j--){
            if(str[j]==' '){
                str[newlen--]='0';
                str[newlen--]='2';
                str[newlen--]='\%';
            }
            else
                str[newlen--]=str[j];
             
        }
             
    }
};


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