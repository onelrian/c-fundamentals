#include <stdio.h>

int main() {
    int rows, columns;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    if (columns < rows) {
        printf("This is not good\n");
    } else {
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= columns - i; j++) {
                printf(" ");
            }
            for (int j = 1; j <= (2 * i - 1); j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
