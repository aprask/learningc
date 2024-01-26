#include <stdio.h>
#include <stdlib.h>

typedef float (*Operation)(float, float);

float lastResult;
float lastNum1;
float lastNum2;
const char* lastOperator;

int numOfOperations;

float add(float num1, float num2) {
    return num1 + num2;
}

float subtract(float num1, float num2) {
    return num1 - num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Error: Division by zero!\n");
        exit(EXIT_FAILURE);
    }
}

void performOperation(float num1, float num2, Operation operation, const char* operatorSymbol) {
    float result = operation(num1, num2);
    printf("%.2f %s %.2f = %.2f\n", num1, operatorSymbol, num2, result);

    lastNum1 = num1;
    lastNum2 = num2;
    lastOperator = operatorSymbol;
    lastResult = result;
}

void retrieveLastOperation(){
    printf("%.2f %s %.2f = %.2f\n", lastNum1, lastOperator, lastNum2, lastResult);
}

int main() {
    float num1, num2;
    int operator;

    while (1) {
        if(numOfOperations < 1) {
            printf("\t\"1\": Add\n\t\"2\": Subtract\n\t\"3\": Multiply\n\t\"4\": Divide\n\t\"6\": Exit\n");
            scanf("%d", &operator);
        } else {
            printf("\t\"1\": Add\n\t\"2\": Subtract\n\t\"3\": Multiply\n\t\"4\": Divide\n\t\"5\": Last Operation\n\t\"6\": Exit\n");
            scanf("%d", &operator);
        }

        switch (operator) {
            case 1:
                printf("Enter the first number: \n");
                scanf("%f", &num1);
                
                printf("Enter the second number: \n");
                scanf("%f", &num2);
                performOperation(num1, num2, add, "+");
                numOfOperations += 1;
                printf("\n");
                break;
            case 2:
                printf("Enter the first number: \n");
                scanf("%f", &num1);
                
                printf("Enter the second number: \n");
                scanf("%f", &num2);
                performOperation(num1, num2, subtract, "-");
                numOfOperations += 1;
                printf("\n");
                break;
            case 3:
                printf("Enter the first number: \n");
                scanf("%f", &num1);
                
                printf("Enter the second number: \n");
                scanf("%f", &num2);
                performOperation(num1, num2, multiply, "*");
                numOfOperations += 1;
                printf("\n");
                break;
            case 4:
                printf("Enter the first number: \n");
                scanf("%f", &num1);
                
                printf("Enter the second number: \n");
                scanf("%f", &num2);
                performOperation(num1, num2, divide, "/");
                numOfOperations += 1;
                printf("\n");
                break;
            case 5:
                retrieveLastOperation();
                printf("\n");
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid operator!\n");
                exit(EXIT_FAILURE);
        }
    }
    return 0;
}
