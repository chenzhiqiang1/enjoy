#include<stdio.h>

int solution(int *a,int n){
	int i=0,j,k,count;
	count=0;
	if(n<3)
		return 0;
	while(i<n-2){
		for(j=i+1;j<n-1;j++){
			for(k=j+1;k<n;k++){
				if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[k]+a[j]>a[i])
					count++;
			}
		}
		i++;
	}
	return count;
}

int main(){ 
  int a[50];
  int n,result;

  scanf("%d",&n);
  for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
  }
  result=solution(a,n);
  printf("%d\n",result);
  return 0;
}