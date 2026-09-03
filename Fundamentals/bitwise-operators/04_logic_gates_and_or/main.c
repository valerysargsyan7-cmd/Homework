#include <stdio.h>

int main(void)
{
    int first_bit = 0;
    int second_bit = 0;

    printf("\nLogic gates: AND / OR\n");

    printf("\nEnter first bit value (0 or 1): ");

    if(scanf("%d", &first_bit) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter 0 or 1.\n");
        return 1;

    }

    printf("Enter second bit value (0 or 1): ");

    if(scanf("%d", &second_bit) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter 0 or 1.\n");
        return 1;

    }

    if((first_bit != 0 && first_bit != 1) || (second_bit != 0 && second_bit != 1)){

        fprintf(stderr, "Error: Bit values must be 0 or 1.\n");
        return 1;

    }

    printf("\nResult of AND: %d\n", first_bit && second_bit);
    printf("\nResult of OR: %d\n", first_bit || second_bit);

    return 0;
}