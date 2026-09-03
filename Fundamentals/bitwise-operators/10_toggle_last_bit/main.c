#include <stdio.h>

int main(void)
{
    int number = 0;

    printf("\nChanging last bit\n");

    printf("\nEnter your number: ");

    if(scanf("%d", &number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    number = number ^ 1;

    printf("\nResult: %d\n", number);

    return 0;
}