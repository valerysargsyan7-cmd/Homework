#include <stdio.h>

int main(void)
{
    int number = 0;
    int thousands = 0;
    int hundreds = 0;
    int tens = 0;
    int units = 0;

    printf("\nLucky number calculating\n");

    printf("\nEnter your four-digit number: ");

    if(scanf("%d", &number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(number < 1000 || number > 9999){

        fprintf(stderr, "Error: Number must contain exactly four digits.\n");
        return 1;

    }

    thousands = number / 1000;
    hundreds = (number / 100) % 10;
    tens = (number / 10) % 10;
    units = number % 10;

    if(thousands + hundreds == tens + units){

        printf("\nLUCKY\n");

    }else{

        printf("\nUNLUCKY\n");
    }

    return 0;
}