#include <stdio.h>

int main() {
    int num, rev = 0;
    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num != 0) {
        int rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }

    printf("The reversed integer is: %d", rev);
    return 0;
}
