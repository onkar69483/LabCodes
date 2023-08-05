# Assignment 2
## Write a C++ program to add two complex numbers by passing structure to a function
```C
#include <stdio.h>

struct Complex
{
    int real;
    int img;
};

void add(int real1,int real2, int imaginary1, int imaginary2){
    printf("\nAddition: %d+%di\n",real1+real2,imaginary1+imaginary2);
}

void subtract(int real1,int real2, int imaginary1, int imaginary2){
    printf("\nSubtraction: %d+%di\n",(real1-real2),(imaginary1-imaginary2));
}

void multiplication(int real1,int real2, int imaginary1, int imaginary2){
    printf("\nMultiplication: %d+%di\n",(real1*real2-imaginary1*imaginary2), (real1*imaginary2 +real2*imaginary1));
}

int main() {
    int choice=0;
    struct Complex c1,c2;
    while(choice<4){
    printf("\nChoose\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Exit!");
    printf("\nEnter choice: ");
    scanf("%d",&choice);
  
    if(choice<4){
    printf("Enter real part of first complex number: ");
    scanf("%d",&c1.real);
    printf("Enter imaginary part of first complex number: ");
    scanf("%d", &c1.img);
    
    printf("Enter real part of second complex number: ");
    scanf("%d",&c2.real);
    printf("Enter imaginary part of second complex number: ");
    scanf("%d", &c2.img);
    
    switch(choice){
        case 1: add(c1.real,c2.real,c1.img,c2.img);
        break;
        case 2: subtract(c1.real,c2.real,c1.img,c2.img);
        break;
        case 3: multiplication(c1.real,c2.real,c1.img,c2.img);
        break;
        case 4: return 0;
        break;
        default: printf("Invalid Choice!");
        break;
    }
}
  }
    
    return 0;
}          
```
