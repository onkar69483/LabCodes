#include <stdio.h>
#include <math.h>

double sqrtRecursive(double n, double guess, double tolerance);

int main() {
    double n, guess, tolerance=1;

    printf("Enter a non-negative number: ");
    scanf("%lf", &n);

    if (n < 0) {
        printf("Error: Cannot calculate square root of negative number.");
        return 1;
    }

    printf("Enter an initial guess: ");
    scanf("%lf", &guess);

    printf("Enter a tolerance: ");
    scanf("%lf", &tolerance);

    printf("The square root of %.2lf is %.5lf\n", n, sqrtRecursive(n, guess, tolerance));

    return 0;
}

double sqrtRecursive(double n, double guess, double tolerance) {
    double new_guess = (guess + n / guess) / 2;
    double diff = fabs(new_guess - guess);

    if (diff < tolerance) {
        return new_guess;
    } else {
        return sqrtRecursive(n, new_guess, tolerance);
    }
}
