#include <stdio.h>
double Mean(int data[], int size) {
    int sum = 0;
    for (int i = 0; i <size; i++) {
        sum += data[i];
    }
    return (double)sum / size;
}
double Median(int data[], int size) {
    if (size % 2 == 0) {
        return (double)(data[size/2-1]+data[size/2])/2;
    } else {
        return data[size / 2];
    }
}
int main() {
    int data[100];
    int size;

    printf("Enter the number of data points: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("Invalid number of data points. Please enter a number between 1 and %d.\n", 100);
        return 1;
    }
    printf("Enter %d data points:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }
    int choice=0;
    while(choice!=3) {
        printf("\nMenu\n");
        printf("1. Calculate Mean\n");
        printf("2. Calculate Median\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Mean: %.2f\n", Mean(data, size));
                break;

            case 2:
                printf("Median: %.2f\n", Median(data, size));
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
