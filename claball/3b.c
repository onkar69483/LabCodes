#include <stdio.h>

int main() {
    double number, squareRoot, guess = 1;

    printf("Enter a number: ");
    scanf("%lf", &number);

    while (guess * guess != number) {
        squareRoot = (guess + number / guess) / 2;
        if (squareRoot == guess) {
            break;
        }
        guess = squareRoot;
    }

    printf("Square root of %lf = %lf", number, squareRoot);

    return 0;
}
