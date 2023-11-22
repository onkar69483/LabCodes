#include <stdio.h>

// Merge function to merge two sorted arrays into a single sorted array
void merge(int arr[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = lb, sorted[ub + 1]; // Initialize indices and temporary array

    // Merge the two sorted arrays into a temporary array 'sorted'
    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            sorted[k] = arr[i];
            i++;
        } else {
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from the left subarray if any
    if (i > mid) {
        while (j <= ub) {
            sorted[k] = arr[j];
            j++;
            k++;
        }
    } else { // Copy remaining elements from the right subarray if any
        while (i <= mid) {
            sorted[k] = arr[i];
            i++;
            k++;
        }
    }

    // Copy elements from the temporary array 'sorted' back to 'arr'
    for (k = lb; k <= ub; k++) {
        arr[k] = sorted[k];
    }
}

// Merge Sort function
void mergeSort(int arr[], int lb, int ub) {
    if (lb < ub) { // Base case to check if array size is greater than 1
        int mid = (lb + ub) / 2; // Calculate the middle index

        // Recursive calls to divide the array into halves and sort them
        mergeSort(arr, lb, mid); // Sort the left half
        mergeSort(arr, mid + 1, ub); // Sort the right half

        merge(arr, lb, mid, ub); // Merge the sorted halves
    }
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Display the array before sorting
    printf("\nBefore Sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Call mergeSort function to sort the array
    mergeSort(arr, 0, size - 1);

    // Display the array after sorting
    printf("\nAfter Sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
