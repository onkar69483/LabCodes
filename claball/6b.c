//EXP 6B


#include <stdio.h>
#include <math.h>

int main() {
    int arr[] = {2, 5, 7, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min = arr[0];
    int max = arr[0];
    float sum = 0;
    float mean = 0;
    float variance = 0;
    float std_dev = 0;

    for(int i=0; i<n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
        sum += arr[i];
    }

    mean = sum / n;

    for(int i=0; i<n; i++) {
        variance += pow(arr[i] - mean, 2);
    }

    variance /= n;
    std_dev = sqrt(variance);

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Variance: %f\n", variance);
    printf("Standard Deviation: %f\n", std_dev);

    return 0;
}