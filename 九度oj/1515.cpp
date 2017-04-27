#include<stdio.h>
#include<math.h>
int main(){
	int N;
	double m;
	scanf("%d",&N);
	if(N<1 || N>5){
		return -1;
	}
	m=(int)pow(10.0,N);
	for(int i=1;i<m;i++){
		printf("%d\n",i);
	}
}
