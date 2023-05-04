#include <stdio.h>  
  
int main()  
{  
    int num, i , rem, sum;  
  
   for(i=101;i<=500;i++) 
    {
        num = i;  
        sum = 0;  
  
        while(num!=0)  
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
