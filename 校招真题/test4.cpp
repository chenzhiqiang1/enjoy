#include<stdio.h>

int main(){
    int n,a[50][2];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    int temp[2][2];
    temp[1][0]=temp[0][0]=a[0][0];
    temp[1][1]=temp[0][1]=a[0][1];
    for(int i=0;i<n;i++){
        if(a[i][0]>temp[0][0])
                temp[0][0]=a[i][0];
        if(a[i][0]<temp[1][0])
               temp[1][0]=a[i][0]; 

        if(a[i][1]>temp[0][1])
                temp[0][1]=a[i][1];
        if(a[i][1]<temp[1][1])
               temp[1][1]=a[i][1]; 
    }
    int x,y;
    x=temp[0][0]-temp[1][0];
	y=temp[0][1]-temp[1][1];
	printf("%d\n",x*y);
	return 0;
}