#include<stdio.h>

int tenTobin(int a){
	int count=0;

	//Time Limit Exceed
	/*int b;
	while(a>0){
		if(a%2)
			count++;
		a=a/2;
	}
	if(a<0){
		b=-a;
		while(b>0){
			if(b%2==0)
				count++;
			b=b/2;
		}
	}*/
	while(a){
		count++;
		a=a & (a-1);
	}
	return count;
}

int Count(int i) {
 int count = 0; 
 unsigned int flag = 1; 
 while(flag){
 if(i & flag)
  count ++;
  flag = flag << 1;
  }
  return count; 
}

int main(){
	int temp,n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
		    printf("%d\n",tenTobin(temp));
			printf("%d\n",Count(temp));
		}
	}
}