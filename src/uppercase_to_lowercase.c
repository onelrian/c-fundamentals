#include <stdio.h>

// This program changes uppercase letters to lowercase
int main() {
    char str[100];

    // Get an uppercase string from the user
    printf("Enter an uppercase string: ");
    scanf("%99[^\n]", str);

    // Convert each character to lowercase
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }

    printf("Lowercase string: %s\n", str);
    return 0;
}
