#include <stdio.h>

int main(void)
{
    int first_number = 0;
    int second_number = 0;
    int sum = 0;

    printf("\nArithmetical Swap\n\n");

    printf("\nEnter your first number: ");

    if(scanf("%d", &first_number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;

    }

    printf("Enter your second number: ");

    if(scanf("%d", &second_number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;

    }

    sum = first_number + second_number;

    printf("\nChanged first number: %d\n", sum - first_number);
    printf("Changed second number: %d\n", sum - second_number);

    return 0;
}