#include <stdio.h>

int grade() {
int s1,s2,s3,s4,s5,per,grade;
printf("Enter marks of subject 1: ");
scanf("%d",&s1);
printf("Enter marks of subject 2: ");
scanf("%d",&s2);
printf("Enter marks of subject 3: ");
scanf("%d",&s3);
printf("Enter marks of subject 4: ");
scanf("%d",&s4);
printf("Enter marks of subject 5: ");
scanf("%d",&s5);

per=(s1+s2+s3+s4+s5)/5;
if(per>=95){
	printf("Your Grade is: A+");
}
else if(per>=90){
	printf("Your Grade is: A");
}
else if(per>=80){
	printf("Your Grade is: B");
}
else if(per>=70){
	printf("Your Grade is: D");
}
else if(per>=60){
	printf("Your Grade is: C");
}
else if(per>=50){
	printf("Your Grade is: P");
}
else{
	printf("You are Fail!");
}
	return 0;
}
