#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quadroots(){
	int a,b,c;
	float r1,r2;
	printf("Enter the coefficients: "); 
	scanf(" %d %d %d",&a,&b,&c);
	float d= b*b-4*a*c;
	if(d==0){
		r1=r2=-b/(2*a);
		printf("Real and equal roots!\nr1=r2 = %f",r1);
	}
	else if(d>0){
		r1=(-b+sqrt(d))/(2*a);
		r2=(-b-sqrt(d))/(2*a);
		printf("Real and unique roots!\nr1=%.2f\nr2=%.2f",r1,r2);
	}
	else{
		printf("Imaginary roots!");
	}
	
}
