#include <stdio.h>
#include <stdlib.h>

double sum(int a,int b){
	return a+b;
}
double subtract(int a,int b){
	return a-b;
}
double product(int a,int b){
	return a*b;
}
double division(int a,int b){
	return a/b;
}

int calculator() {
	printf("Sum: %.2lf\n",sum(10,5));
	printf("Difference: %.2lf\n",subtract(10,5));
	printf("Product: %.2lf\n",product(10,5));
	printf("DIvision: %.2lf\n",division(10,5));
	
/*	double a,b;
	char c;
	printf("Enter number 1: ");
	scanf("%lf",&a);
	printf("Enter number 2: ");
	scanf("%lf",&b);
	printf("Press + , - , * or / : ");
	scanf(" %c",&c);
	switch(c){
		case '+':
			printf("Sum: %.2lf",sum(a,b));
			break;
		case '-':
			printf("Difference: %.2lf",subtract(a,b));
			break;
		case '*':
			printf("Product: %.2lf",product(a,b));
			break;
		case '/':
			printf("Division: %.2lf",division(a,b));
			break;
			default:
				printf("Invalid Input!");
	}*/
	return 0;
}

