#include <stdio.h>

int main() {
    int left_corner0 = 48, left_corner1 = 65;
    int right_corner0 = 57, right_corner1 = 90;
    int Arr0[10], Arr1[26];
    int i = 0, j = 0;

    if (left_corner0 <= right_corner0) {
        while (left_corner0 <= right_corner0) {
            Arr0[i] = left_corner0;
            left_corner0++;
            i++;
        }
    }

    if (left_corner1 <= right_corner1) {
        while (left_corner1 <= right_corner1) {
            Arr1[j] = left_corner1;
            left_corner1++;
            j++;
        }
    }

    printf("Arr0: ");
    for (int k = 0; k < i; k++) {
        printf("%c ", Arr0[k]);
    }
    printf("\n");

    printf("Arr1: ");
    for (int k = 0; k < j; k++) {
        printf("%c ", Arr1[k]);
    }
    printf("\n");

    return 0;
}
