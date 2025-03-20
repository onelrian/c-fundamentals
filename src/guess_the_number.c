#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    char verifier = 'f';
    int a = (rand() % 100) + 1, b, num, mid, lower, upper, temp;

    do {
        b = (rand() % 100) + 1;
    } while (b == a);

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    mid = (a + b) / 2;
    lower = mid / 2;
    upper = 3 * (mid / 2);

    while (verifier == 'f') {
        printf("Guess a number: ");
        if (scanf("%d", &num) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (num < mid && num > lower) {
            printf("A little bit too small\n");
        } else if (num < lower) {
            printf("Too small\n");
        } else if (num > mid && num < upper) {
            printf("A little bit too big\n");
        } else if (num > upper) {
            printf("Too big\n");
        } else if (num == mid) {
            printf("Correct!\n");
            verifier = 'T';
        }

        printf("The boundaries are %d, %d\n", a, b);
    }

    return 0;
}
