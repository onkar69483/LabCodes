#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void conditional(){
	int age;
	printf("Enter your age: ");
	scanf("%d",&age); //REMEMBER THAT NEVER FORGET TO PUT THE '&' AS YOU ARE STORING THE VALUE IN MEMORY AND NOT IN THE VARIABLE
	if(age>=18){ //YOU ALWAYS FORGET TO PUT THE '&'
		printf("You are elidgible to vote!");
	}
	else{
		printf("You are not elidgible to vote!");
		
	}
}

