#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int i, n, j, k, temp;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0) {
        printf("Invalid size. Must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    int *N = malloc(n * sizeof(int));
    if (!N) {
        perror("Memory allocation failed");
        return 1;
    }

    printf("Enter numbers (Enter -1 to stop early):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &N[i]);
        if (N[i] == -1) {
            n = i;
            break;
        }
    }

    printf("Your series of numbers:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", N[i]);
    }
    printf("\n");

    // Bubble Sort (Optimized)
    for (k = 0; k < n - 1; k++) {
        int swapped = 0;
        for (i = 0; i < n - 1 - k; i++) {
            if (N[i] > N[i + 1]) {
                temp = N[i];
                N[i] = N[i + 1];
                N[i + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break; // Stop if already sorted
    }

    printf("Sorted numbers:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", N[i]);
    }
    printf("\n");

    free(N); // Free allocated memory
    return 0;
}
