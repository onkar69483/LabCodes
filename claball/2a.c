#include<stdio.h>
int main(){
    int n,i,c=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    if(n==1){
        printf("Not a prime number nor composite!");
    }
    else{
    for(i=2;i<n;i++){
        if(n%i==0){
          c=1;
          break;
        }
    }
    if(c==0){
        printf("Prime Number!");
    }
    else{
        printf("Composite Number!");
    }
    }
    return 0;
}