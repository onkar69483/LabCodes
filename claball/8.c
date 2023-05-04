#include <stdio.h>

int main() {
    int matrix1[3][3], matrix2[3][3], add[3][3], sub[3][3];
    int i, j, k;
    printf("Enter the elements of first matrix:\n"); 
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the elements of second matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
           add[i][j]=matrix1[i][j]+matrix2[i][j];
           sub[i][j]=matrix1[i][j]-matrix2[i][j];
        }
    }
   printf("Addition: \n");
   for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
        	printf("%d ",add[i][j]);
        }
        printf("\n");
    }
printf("\nSubtraction: \n");
   for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
        	printf("%d ",sub[i][j]);
        }
        printf("\n");
    }
  printf("\nmatrix1: \n");
   for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
        	printf("%d ",matrix1[i][j]);
        }
        printf("\n");
    }
 printf("\nTranspose of matrix1: \n");
   for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
        	printf("%d ",matrix1[j][i]);
        }
        printf("\n");
    }

    return 0;
}
