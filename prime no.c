#include<stdlib.h>
#include<stdio.h>

void IsPrime(){
	int num,i;
	int count=0;
	printf("Enter a number: ");
	scanf(" %d",&num);
	if (num>1){
		for(i=2;i<num;i++){
			if(num%i==0){
				count++;
			}
		}
	}
	if (count>0){
		printf("%d is a not a Prime Number!",num);
	}
	else{
		printf("%d is a Prime Number!",num);
	}
	}

