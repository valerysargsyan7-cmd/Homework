#include <stdio.h>

int main(void)
{
    int number = 0;

    printf("\nCheck even\n");

    printf("\nEnter your number: ");

    if(scanf("%d", &number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(number % 2 == 0){

        printf("\nNumber is even\n");

    }else{

        printf("\nNumber is odd\n");
    }

    return 0;
}