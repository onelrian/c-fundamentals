#include <stdio.h>

int add_two(int num1, int num2);
int sub_two(int num1, int num2);
int multi_two(int num1, int num2);
float div_two(int num1, int num2);
float av_two(int num1, int num2);

int main() {
    int num1, num2;
    char op;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("Enter an operator (+, -, *, $, /): ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
            printf("%d\n", add_two(num1, num2));
            break;
        case '-':
            printf("%d\n", sub_two(num1, num2));
            break;
        case '*':
            printf("%d\n", multi_two(num1, num2));
            break;
        case '/':
            if (num2 != 0)
                printf("%.2f\n", div_two(num1, num2));
            else
                printf("Error: Division by zero is not allowed.\n");
            break;
        case '$':
            printf("%.2f\n", av_two(num1, num2));
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;
    }

    return 0;
}

int add_two(int num1, int num2) {
    return num1 + num2;
}

int sub_two(int num1, int num2) {
    return num1 - num2;
}

int multi_two(int num1, int num2) {
    return num1 * num2;
}

float div_two(int num1, int num2) {
    return (float) num1 / num2;
}

float av_two(int num1, int num2) {
    return (num1 + num2) / 2.0;
}
