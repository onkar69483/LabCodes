#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int i;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // Find the length of the first string
    i = 0;
    while (str1[i] != '\0') {
        i++;
    }
    int len_str1 = i;

    // Find the length of the second string
    i = 0;
    while (str2[i] != '\0') {
        i++;
    }
    int len_str2 = i;

    // Compare the lengths of the two strings
    if (len_str1 > len_str2) {
        printf("The longer string is: %s\n", str1);
    }
    else if (len_str1 < len_str2) {
        printf("The longer string is: %s\n", str2);
    }
    else {
        printf("The two strings are of equal length\n");
    }

    return 0;
}
