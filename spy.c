#include <stdio.h>  
  
int spy()  
{  
    int num, i , rem, sum,prod;  
  
   for(i=1;i<=500;i++) 
    {  
        num = i;  
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
            printf("%d\n", i);  
        }  
  
        
    }  
  
     return 0;  
}  
