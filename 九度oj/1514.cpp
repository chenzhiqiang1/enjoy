#include <stdio.h>

//判断两个小数是否相等
bool equal(double d1,double d2){
    return (d1 - d2 > -0.0000001) && (d1 - d2 < 0.0000001) ? true : false;
}

double PowerPositiveExponent(double base, int exponent)
{
	 double result = 1.0;
	 for(; exponent>0; exponent /= 2)
	 {
		  if(exponent % 2 == 1){
			 result *= base;
		  }
		  base *= base;
	 }
	 return result;
}

double Power(double base, int exponent)
{
	 double result;
	 if(equal(base,0)==false && exponent == 0){
		return result = 1.00;
	 }
	 else if(equal(base,0)==true){
		return result=0.00;
	 }
	 else{
	  if(exponent > 0){
		result = PowerPositiveExponent(base,exponent);
	  }
	  if(exponent < 0){
		   result = PowerPositiveExponent(base, -exponent);
		   result = 1.0/result;
	  }
	 }
	return result;
}


int main(){
	int exponent,T;
	double base;
	scanf("%d",&T);
	while(T--){
		scanf("%lf %d",&base,&exponent);
		double result;
		result=Power(base,exponent);
		if(result==0){
			if(base==0 && exponent<=0)
				printf("INF\n");
			else
				printf("%.2ef\n",0.00);
		}
		else
			printf("%.2ef\n",result);
	}
}

//AC
//#include<iostream>  
//#include<stdio.h>  
//#include <memory.h>  
//#include <math.h>  
//#include <stdlib.h>  
//using namespace std;  
//  
//double PowerWithUnsignedExponent (double base, unsigned int exponent){  
//    if (exponent == 0)  
//        return 1.0;  
//    if (exponent == 1)  
//        return base;  
//    double ans = PowerWithUnsignedExponent (base, exponent >> 1);  
//    ans *= ans;  
//    if (exponent & 0x01 == 1){  //等价于exponent/2==1
//        ans *= base;  
//    }  
//    return ans;  
//}  
//
//double power(double base,int exp){  
//    if(base ==0||(base==0&&exp>0)){  
//        return 0.0;  
//    }  
//    unsigned int absExp = (unsigned int)abs (exp);  
//    if(exp<0){  
//        absExp = (unsigned int)(-exp);  
//    }  
//    double result = PowerWithUnsignedExponent(base,absExp);  
//    if(exp<0){  
//        result = 1.0/result;  
//    }  
//    return result;  
//}  
//  
//  
//int main(){  
//    int n,exp;  
//    double base;  
//    scanf("%d",&n);  
//    while(n--){  
//        scanf("%lf%d",&base,&exp);  
//        double ans = power(base,exp);  
//        if (ans != 0.0)  
//            printf ("%.2ef\n", ans);  
//        else if (base == 0.0 && exp >= 0)  
//            printf ("%.2ef\n", 0.0);  
//        else  
//            printf ("INF\n");  
//    }  
//    return 0;  
//}
