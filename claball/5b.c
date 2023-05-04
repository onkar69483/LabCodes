#include <stdio.h>

int main() {
    int num, digit, sum = 0, prod = 1;
    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) {
        digit = num % 10;
        sum += digit;
        prod *= digit;
        num /= 10;
    }

    if (sum == prod) {
        printf("The number is a Spy number.");
    } else {
        printf("The number is not a Spy number.");
    }

    return 0;
}
