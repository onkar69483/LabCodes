#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int i, j;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // Find the length of the first string
    i = 0;
    while (str1[i] != '\0') {
        i++;
    }

    // Concatenate the second string to the first string
    j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';  // Don't forget to add the null character at the end of the concatenated string

    // Print the concatenated string
    printf("Concatenated string: %s\n", str1);

    return 0;
}
