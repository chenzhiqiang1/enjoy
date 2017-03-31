#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;


void solute(vector<int> buff,int target){
	int len=buff.size();
	int temp,s3;
	sort( buff.begin() , buff.end() ); 
	
	for(int i=0;i<len-2;i++){
		for(int j=i+1;j<len-1;j++){
			s3=target-buff[i]-buff[j];
			vector<int>::iterator temp;
			temp = find(buff.begin(),buff.end(),s3);
			if(temp != buff.end() && s3 >= buff[j])
				cout << buff[i]<<"  "<<buff[j]<<"  "<<s3<<endl;
		}
	}
}



void main(){
	
	int array[]={-1,0,1,2,-1,-4};
	vector<int> buff(array,array+6);
	solute(buff,0);
}