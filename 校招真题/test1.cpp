#include<string>
#include<iostream>  
using namespace std;  

int calc(string a,string b){
	int maxtri[50][50]={0};
	int max=0; 
    int la = a.size();  
    int lb = b.size();  

	for(int i=0;i<la;i++){
		for(int j=0;j<lb;j++){
			if(a[i]==b[j]){
				if(i==0 || j==0){
					maxtri[i][j]=1;
				}
				else
					maxtri[i][j]=maxtri[i-1][j-1]+1;
			}
		}
	}
	
	for(int i=0;i<la;i++){
		for(int j=0;j<lb;j++){
			if(max<maxtri[i][j])
				max=maxtri[i][j];	
		}
	}
	return max;
}

int main(){
	int result;
	string a,b;
	getline(cin, a);  
    getline(cin, b);  

	result=calc(a,b);
	cout<<result<<endl;
	return 0;
}



//#include<iostream>  
//#include<string>  
//using namespace std;  
//  
//int main()  
//  
//{  
//  
//    int dp[50][50] = {0};  
//  
//    string input1;  
//  
//    string input2;  
//  
//    getline(cin, input1);  
//  
//    getline(cin, input2);  
//  
//    int len1 = input1.size();  
//  
//    int len2 = input2.size();  
//  
//    for(int i =0; i < len1; ++i)  
//  
//    {  
//  
//    for(int j =0; j < len2; ++j)  
//  
//    {  
//  
//    if(input1[i] == input2[j])  
//  
//    {  
//  
//    if(i ==0|| j ==0)  
//  
//    dp[i][j] =1;  
//  
//    else  
//  
//    dp[i][j] =1+ dp[i -1][j -1];  
//  
//  }  
//  
//  else  
//  
//   dp[i][j] =0;  
//  
//	}
//  }  
//  
//  int temp =0;  
//  
//   for(int i =0; i < len1; ++i)  
//  
//   {  
//  
//    for(int j =0; j < len2; ++j)  
//  
//   {  
//  
//    if(temp < dp[i][j])  
//  
//   temp = dp[i][j];  
//  
//   }  
//  
//   }  
//  
// cout << temp << endl;  
//  
//   return 0;  
//}