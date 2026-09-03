#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num = 0;

    printf("\nEnter an integer: ");

    /* Preserve original scanf approach, but validate user input */
    if(scanf("%d", &num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("You entered: %d\n", num);

    return 1;
}