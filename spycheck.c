#include <stdio.h>  
  
int spycheck()  
{  
    int num, rem, sum,prod; 
	printf("Enter a number: ") ;
   scanf("%d",&num);
        sum = 0;  
        prod= 1;
        while(num)  
        {  
            rem = num % 10;  
            sum = sum + rem;  
            prod = prod * rem;
            num = num / 10;  
        }  
  
        if(prod == sum)  
        {  
            printf("It is spy number!");  
        }  
        else{
        	printf("It is not a spy number!");
        }
  
     return 0;  
}  
