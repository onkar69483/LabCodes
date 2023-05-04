#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter the size of the arrays: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the arrays
    int *arr1 = (int *) malloc(size * sizeof(int));
    int *arr2 = (int *) malloc(size * sizeof(int));
    int *result = (int *) malloc(size * sizeof(int));

    // Prompt the user to enter the elements of the arrays
    printf("Enter the elements of the first array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of the second array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr2[i]);
    }

    // Calculate the sum of the corresponding elements
    for (int i = 0; i < size; i++) {
        result[i] = arr1[i] + arr2[i];
    }

    // Print the resultant array
    printf("Resultant array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr1);
    free(arr2);
    free(result);

    return 0;
}
