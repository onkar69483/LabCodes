#include <stdio.h>
#include <math.h>

void add(int real1,int real2, int imaginary1, int imaginary2){
	printf("\nAddition: %d+%di\n",real1+real2,imaginary1+imaginary2);
}

void subtract(int real1,int real2, int imaginary1, int imaginary2){
	printf("\nSubtraction: %d+%di\n",abs(real1-real2),abs(imaginary1-imaginary2));
}

void multiplication(int real1,int real2, int imaginary1, int imaginary2){
	printf("\nMultiplication: %d+%di\n",(real1*real2-imaginary1*imaginary2), (real1*imaginary2 +real2*imaginary1));
}

int main() {
    int real1,real2,imaginary1,imaginary2,choice=0;
    
    while(choice<4){
    printf("\nChoose\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Exit!");
    printf("\nEnter choice: ");
    scanf("%d",&choice);
  
    if(choice<4){
    printf("Enter real part of first complex number: ");
    scanf("%d",&real1);
    printf("Enter imaginary part of first complex number: ");
    scanf("%d", &imaginary1);
    
    printf("Enter real part of second complex number: ");
    scanf("%d",&real2);
    printf("Enter imaginary part of second complex number: ");
    scanf("%d", &imaginary2);
    
    switch(choice){
        case 1: add(real1,real2,imaginary1,imaginary2);
        break;
        case 2: subtract(real1,real2,imaginary1,imaginary2);
        break;
        case 3: multiplication(real1,real2,imaginary1,imaginary2);
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
