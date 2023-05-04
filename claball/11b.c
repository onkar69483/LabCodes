#include <stdio.h>

int main() {
    char str[100], substr[100];
    int i, j, flag;

    printf("Enter the main string: ");
    scanf("%s", str);

    printf("Enter the substring: ");
    scanf("%s", substr);

    // Find the length of the main string and the substring
    int len_str = 0;
    while (str[len_str] != '\0') {
        len_str++;
    }

    int len_substr = 0;
    while (substr[len_substr] != '\0') {
        len_substr++;
    }

    // Check for the occurrence of the substring in the main string
    flag = 0;
    for (i = 0; i <= len_str - len_substr; i++) {
        for (j = 0; j < len_substr; j++) {
            if (str[i+j] != substr[j]) {
                break;
            }
        }
        if (j == len_substr) {
            flag = 1;
            printf("Substring found at index %d\n", i);
        }
    }

    if (flag == 0) {
        printf("Substring not found\n");
    }

    return 0;
}
