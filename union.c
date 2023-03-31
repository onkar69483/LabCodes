#include <stdio.h>

int union() {
     int arr1[10], arr2[10];
    int i, j, k, size1, size2;
    printf("Enter the elements of first array:\n");
    for (i = 0; i <10; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the elements of second array:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr2[i]);
    }
    printf("\nCommon elements: ");
    for (i = 0; i < 10; i++) {
        for (j = 0; j <10; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                break;
            }
        }
    }
    printf("\nIntersection elements: ");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
            if (arr1[i] == arr2[j]) {
                for (k = 0; k < i; k++) {
                     if (arr1[k] == arr1[i]) {
                        break;
                    }
                }
                 if (k == i) {
                    printf("%d ", arr1[i]);
                }
                break;
            }
        }
    }

    return 0;
}
