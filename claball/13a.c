#include <stdio.h>

// function to find the factorial of a number using recursion
int factorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}

int main()
{
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    
    if(n < 0)
    {
        printf("Error: Enter a non-negative integer!\n");
    }
    else
    {
        printf("Factorial of %d is %d\n", n, factorial(n));
    }
    
    return 0;
}
