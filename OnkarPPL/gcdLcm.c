#include <stdio.h>

int Gcd(int num1, int num2) {
    if (num2 == 0)
        return num1;
    return Gcd(num2, num1 % num2);
}

int Lcm(int num1, int num2) {
    return (num1 * num2) / Gcd(num1, num2);
}

int main() {
    int choice, num1, num2;
    while(choice!=3){
        printf("\nMenu\n");
        printf("1. GCD\n");
        printf("2. LCM\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("GCD: %d\n", Gcd(num1, num2));
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("LCM: %d\n", Lcm(num1, num2));
                break;

            case 3:
                printf("Exiting!\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } 
    return 0;
}
