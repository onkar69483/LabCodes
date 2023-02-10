#include<stdlib.h>
#include<stdio.h>

void Starpattern(){
    int num,i,j;
    printf("Enter number: ");
    scanf("%d",&num);
      for(i=0;i<num;i++){
          for( j=0;j<=i;j++){
          printf("*");
      }
      printf("\n");
      }
	}
