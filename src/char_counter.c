#include <stdio.h>

int main() {
    int i, n, count = 0, count1 = 0, count2 = 0, count3 = 0;
    
    printf("How long would you want your test to be: ");
    scanf("%d", &n);

    char in[n];

    printf("Enter characters: ");
    scanf(" %[^\n]", in); // Allows reading a full line of input

    for (i = 0; i < n; i++) {
        if (in[i] >= '0' && in[i] <= '9') {
            count += 1;
        } else if (in[i] >= 'A' && in[i] <= 'Z') {
            count1 += 1;
        } else if (in[i] >= 'a' && in[i] <= 'z') {
            count2 += 1;
        } else {
            count3 += 1;
        }
    }

    printf("There are %d integers\n", count);
    printf("There are %d uppercase letters\n", count1);
    printf("There are %d lowercase letters\n", count2);
    printf("There are %d special characters\n", count3);

    return 0;
}
