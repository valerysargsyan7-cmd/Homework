#include <stdio.h>

int main(void)
{
    int first_num = 0;
    int second_num = 0;
    int result = 0;

    printf("\nRemainder calculation\n");

    printf("Enter first number: ");
    if(scanf("%d", &first_num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("Enter second number: ");
    if(scanf("%d", &second_num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(second_num == 0){

        fprintf(stderr, "Error: Division by zero is not allowed.\n");
        return 1;

    }

    result = first_num % second_num;

    printf("Remainder: %d\n", result);

    return 0;
}