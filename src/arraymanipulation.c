#include <stdio.h>

int main() {
    int arr[10], i, j, sum = 0;
    float average;

    // Taking input
    printf("Enter 10 numbers of your choice:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Displaying entered numbers
    printf("The numbers you chose are:\n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    // Sorting using Bubble Sort
    for (i = 0; i < 10 - 1; i++) {
        for (j = 0; j < 10 - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display maximum and minimum values
    printf("The maximum and minimum values in the series are:\n");
    printf("%d and %d respectively\n", arr[9], arr[0]);

    // Compute sum and average
    for (i = 0; i < 10; i++) {
        sum += arr[i];
    }
    average = sum / 10.0; // Use 10.0 to ensure floating-point division

    printf("The sum of the numbers you chose is:\n%d\n", sum);
    printf("And the average is:\n%.2f\n", average);

    // Display sorted numbers
    printf("In ascending order, the numbers you chose are:\n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    printf("Thanks for the participation!\n");

    return 0;
}
