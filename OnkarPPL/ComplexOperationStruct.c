#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent complex numbers
struct Complex {
    float real;
    float imaginary;
};

// Function to convert complex number string to complex structure
struct Complex parseComplex(const char* complexStr) {
    struct Complex num;
    char* end;
    num.real = strtof(complexStr, &end);
    if (*end == '+') {
        num.imaginary = strtof(end + 1, &end);
    } else {
        num.imaginary = 0.0;
    }
    return num;
}

// Function to add two complex numbers
struct Complex add(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

// Function to subtract two complex numbers
struct Complex subtract(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real - num2.real;
    result.imaginary = num1.imaginary - num2.imaginary;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiply(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
    result.imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
    return result;
}

int main() {
    char complexStr1[100], complexStr2[100];
    struct Complex num1, num2, result;

    // Input the first complex number
    printf("Enter the first complex number (in the format 'a+bi'): ");
    scanf("%s", complexStr1);

    // Input the second complex number
    printf("Enter the second complex number (in the format 'a+bi'): ");
    scanf("%s", complexStr2);

    // Convert complex number strings to complex structures
    num1 = parseComplex(complexStr1);
    num2 = parseComplex(complexStr2);

    // Perform addition
    result = add(num1, num2);
    printf("Addition: %.2f + %.2fi\n", result.real, result.imaginary);

    // Perform subtraction
    result = subtract(num1, num2);
    printf("Subtraction: %.2f + %.2fi\n", result.real, result.imaginary);

    // Perform multiplication
    result = multiply(num1, num2);
    printf("Multiplication: %.2f + %.2fi\n", result.real, result.imaginary);

    return 0;
}
