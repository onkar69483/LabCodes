#include <stdio.h>

double CtoF(double Celcius){
    double Fahrenheit = (Celcius*9/5)+32;
    return Fahrenheit;
}

double FtoC(double Fahrenheit) {
    double Celcius = (Fahrenheit - 32) * 5 / 9;
    return Celcius;
}

int main(){
    double temp;
    int choice=0;
    printf("1.Celcius to Fahrenheit");
    printf("\n2.Fahrenheit to Celcius");
    printf("\n3.Quit");
    while(choice!=3){
    printf("\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: 
        printf("Enter temperature in Celcius: ");
        scanf("%lf",&temp);
        printf("Temperature: %lfF",CtoF(temp));
        break;
        case 2: 
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf",&temp);
        printf("Temperature: %lfC",FtoC(temp));
        break;
        case 3: 
        printf("Exiting!");
        return 0;
        default: printf("Invalid Input!");
        break;
    }
    }
    return 0;
}

