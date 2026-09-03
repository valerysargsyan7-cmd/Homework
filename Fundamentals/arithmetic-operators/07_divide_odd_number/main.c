#include <stdio.h>

int main(void)
{
    int number = 0;
    float result = 0.0f;

    printf("\nDivide odd number by two\n");

    printf("\nEnter your odd number: ");

    if(scanf("%d", &number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(number % 2 == 0){

        fprintf(stderr, "Error: The number must be odd.\n");
        return 1;

    }

    result = number / 2.0f;

    printf("\nResult: %.2f\n", result);

    return 0;
}