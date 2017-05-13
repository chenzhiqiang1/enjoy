//#include<stdio.h>
//
//int max_score(int score[],int A,int B){
//    int M;
//	if(A==B)
//		M=score[A];
//    else if (A < B){
//        M = score[A];
//        for(int i = A + 1 ; i <= B; i++){
//            if(M < score[i]){
//                M = score[i];
//            }
//        }
//    }
//    else{
//        M = score[B];
//        for(int i = B + 1 ; i <= A; i++){
//            if(M < score[i]){
//                M = score[i];
//            }
//        }
//    }
//    return M;
//}
//
//int main(){
//    int N,M,A,B,i,j;
//    char C;
//	int buff[30001];
		//scanf("%c..")这样报错
//    while(scanf("%d %d",&N,&M)!=EOF){
//		if(N>30000 || N<=0 || M>=5000 || M<=0)
//			break;
//        for(i=1;i<=N;i++){
//            scanf("%d",&buff[i]);
//        }
//        for(j=1;j<=M;j++){
//            scanf("%c %d %d",&C,&A,&B);
//            if(C=='Q'){
//                printf("%d\n",max_score(buff, A, B));
//            }
//            else if(C=='U'){
//                buff[A]=B;
//            }
//        }   
//    }
//	return 0;
//}


#include<iostream>
    
//选出最大的
int max_score(int score[],int A,int B){
    int M;
	if(A==B)
		M=score[A];
    else if (A < B){
        M = score[A];
        for(int i = A + 1 ; i <= B; i++){
            if(M < score[i]){
                M = score[i];
            }
        }
    }
    else{
        M = score[B];
        for(int i = B + 1 ; i <= A; i++){
            if(M < score[i]){
                M = score[i];
            }
        }
    }
    return M;
}
    
int main(){
    int n,m;
    int num[30001],a,b;
    char c;
           
    int i ,j;
           
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        for(j=1;j<=m;j++){
            scanf(" %c%d%d",&c,&a,&b);
            if(c=='U')
                num[a] = b;
            else if(c=='Q')
                printf("%d\n",max_score(num, a, b));
        }
    }
    return 0;
    
}