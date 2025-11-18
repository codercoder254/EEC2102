#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    char op;
    printf("Enter an operator (+, -, *, /, %%): ");
    scanf(" %c", &op);
    int result;

    switch(op) {
        case '+':
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
                printf("Result: %d\n", result);
            } else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            break;

        case '%':
            if(num2 != 0) {
                result = num1 % num2;
                printf("Result: %d\n", result);
            } else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            break;
            
        default:
            printf("Error: Invalid operator!\n");
            return 1;
    }
}