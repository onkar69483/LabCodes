#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int set1[MAX_SIZE], set2[MAX_SIZE], union_set[MAX_SIZE * 2], intersection_set[MAX_SIZE];
    int n1, n2, i, j, k, found;

    // Reading set 1
    printf("Enter the number of elements in set 1: ");
    scanf("%d", &n1);
    printf("Enter the elements of set 1:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &set1[i]);
    }

    // Reading set 2
    printf("Enter the number of elements in set 2: ");
    scanf("%d", &n2);
    printf("Enter the elements of set 2:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &set2[i]);
    }

    // Union of sets
    k = 0;
    for (i = 0; i < n1; i++) {
        union_set[k++] = set1[i];
    }
    for (i = 0; i < n2; i++) {
        found = 0;
        for (j = 0; j < n1; j++) {
            if (set2[i] == set1[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            union_set[k++] = set2[i];
        }
    }

    // Intersection of sets
    k = 0;
    for (i = 0; i < n1; i++) {
        found = 0;
        for (j = 0; j < n2; j++) {
            if (set1[i] == set2[j]) {
                found = 1;
                break;
            }
        }
        if (found) {
            intersection_set[k++] = set1[i];
        }
    }

    // Printing union of sets
    printf("\nUnion of set 1 and set 2: { ");
    for (i = 0; i < k; i++) {
        printf("%d ", union_set[i]);
    }
    printf("}\n");

    // Printing intersection of sets
    printf("Intersection of set 1 and set 2: { ");
    for (i = 0; i < k; i++) {
        printf("%d ", intersection_set[i]);
    }
    printf("}\n");

    return 0;
}
