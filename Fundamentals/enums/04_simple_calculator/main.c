#include <stdio.h>

enum Operation
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

int main(void)
{
    enum Operation operation;
    int operation_input = 0;
    int first_number = 0;
    int second_number = 0;

    printf("\n=== Simple Calculator ===\n\n");

    printf("Enter first number: ");

    if(scanf("%d", &first_number) != 1){

        fprintf(stderr, "[ERROR] Invalid first number.\n");
        return 1;

    }

    printf(
        "Enter operation:\n"
        "  0 - Add\n"
        "  1 - Subtract\n"
        "  2 - Multiply\n"
        "  3 - Divide\n\n"
        "Choice: "
    );

    if(scanf("%d", &operation_input) != 1){

        fprintf(stderr, "[ERROR] Invalid operation.\n");
        return 1;

    }

    if(operation_input < ADD || operation_input > DIVIDE){

        fprintf(stderr, "[ERROR] Invalid operation.\n");
        return 1;

    }

    operation = (enum Operation)operation_input;

    printf("Enter second number: ");

    if(scanf("%d", &second_number) != 1){

        fprintf(stderr, "[ERROR] Invalid second number.\n");
        return 1;

    }

    if(operation == DIVIDE && second_number == 0){

        fprintf(stderr, "[ERROR] Division by zero is not allowed.\n");
        return 1;

    }

    switch(operation){

        case ADD:
            printf("\n[SUCCESS] Result: %d\n", first_number + second_number);
            break;

        case SUBTRACT:
            printf("\n[SUCCESS] Result: %d\n", first_number - second_number);
            break;

        case MULTIPLY:
            printf("\n[SUCCESS] Result: %d\n", first_number * second_number);
            break;

        case DIVIDE:
            printf("\n[SUCCESS] Result: %d\n", first_number / second_number);
            break;

        default:
            fprintf(stderr, "[ERROR] Invalid operation.\n");
            return 1;
    }

    return 0;
}