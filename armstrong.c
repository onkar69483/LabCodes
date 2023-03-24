#include <stdio.h>  
  
int armstrong()  
{  
    int num, i , rem, sum;  
  
   for(i=1;i<=500;i++) 
    {
        num = i;  
        sum = 0;  
  
        while(num)  
        {  
            rem = num % 10;  
            sum = sum + (rem * rem * rem);  
            num = num / 10;  
        }  
  
        if(i == sum)  
        {  
            printf("%d\n", i);  
        }  
  
        
    }  
  
     return 0;  
}  
