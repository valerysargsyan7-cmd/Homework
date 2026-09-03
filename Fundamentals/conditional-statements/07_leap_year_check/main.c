#include <stdio.h>

int main(void)
{
    int year = 0;

    printf("\nLeap year\n");

    printf("\nEnter year: ");

    if(scanf("%d", &year) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(year <= 0){

        fprintf(stderr, "Error: Year must be greater than zero.\n");
        return 1;

    }

    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){

        printf("\nThe year is a leap year\n");

    }else{

        printf("\nThe year is not a leap year\n");
    }

    return 0;
}