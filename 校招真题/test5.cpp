#include<stdio.h>

bool solution(int *a,int n){
	int i,j,left,right;
	left=right=1;
	for(i=0;i<n-1;i++){
		j=i+1;
		int temp1=i;
		int temp2=j;
		left=right=1;
		do{
			left*=a[temp1];
		}while(temp1--);
		while(temp2<n){
			right*=a[temp2++];
		}
		if(left==right)
			return true;
		
	}
	return false;
}

int main(){
    int n,a[20],i,temp,count;
	bool flag;
    scanf("%d",&n);
    i=0;
	temp=n;
	while(temp){
		i++;
		temp=temp/10;
	}
	count=i;
	while(n){
		a[--i]=n%10;
		n=n/10;
	}
    flag=solution(a,count);
	if(flag==true)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}