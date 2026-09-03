#include <stdio.h>

int main(void)
{
    int number = 0;

    printf("\nOdd or even\n");

    printf("\nEnter your number: ");

    if(scanf("%d", &number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(number & 1){

        printf("\nODD\n");

    }else{

        printf("\nEVEN\n");
    }

    return 0;
}