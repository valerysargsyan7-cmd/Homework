#include <stdio.h>

int main(void)
{
    int number = 0;
    int first_digit = 0;
    int second_digit = 0;
    int third_digit = 0;

    printf("\nReversing three-digit number\n\n");

    printf("Enter your number: ");

    if(scanf("%d", &number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;

    }

    if(number < 100 || number > 999){

        fprintf(stderr, "Error: Number must contain exactly three digits.\n");
        return 1;

    }

    first_digit = number / 100;
    second_digit = (number / 10) % 10;
    third_digit = number % 10;

    printf("\nReversed number: %d%d%d\n",
           third_digit,
           second_digit,
           first_digit);

    return 0;
}