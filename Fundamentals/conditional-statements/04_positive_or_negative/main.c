#include <stdio.h>

int main(void)
{
    int number = 0;

    printf("\nPositive or negative\n");

    printf("\nEnter your number: ");

    if(scanf("%d", &number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(number > 0){

        printf("\nNumber is positive\n");

    }else if(number < 0){

        printf("\nNumber is negative\n");

    }else{

        printf("\nNumber is zero\n");
    }

    return 0;
}