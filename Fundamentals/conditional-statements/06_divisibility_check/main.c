#include <stdio.h>

int main(void)
{
    int number = 0;
    int divisor1 = 0;
    int divisor2 = 0;

    printf("\nDivisibility check\n");

    printf("\nEnter the number to check: ");

    if(scanf("%d", &number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("Enter the first divisor: ");

    if(scanf("%d", &divisor1) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("Enter the second divisor: ");

    if(scanf("%d", &divisor2) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(divisor1 == 0 || divisor2 == 0){

        fprintf(stderr, "Error: Division by zero is not allowed.\n");
        return 1;

    }

    if(number % divisor1 == 0 && number % divisor2 == 0){

        printf("\nNumber %d is divisible by both %d and %d\n", number, divisor1, divisor2);

    }else{

        printf("\nNumber %d is NOT divisible by both %d and %d\n", number, divisor1, divisor2);

    }

    return 0;
}