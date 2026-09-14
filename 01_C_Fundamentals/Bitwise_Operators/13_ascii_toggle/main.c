#include <stdio.h>

int main(void)
{
    char symbol = '\0';

    printf("\nASCII Toggle\n\n");

    printf("Enter your letter: ");

    if(scanf(" %c", &symbol) != 1){

        fprintf(stderr, "Error: Failed to read a character.\n");
        return 1;

    }

    if((symbol < 'A' || symbol > 'Z') &&
       (symbol < 'a' || symbol > 'z')){

        fprintf(stderr, "Error: Please enter an English letter.\n");
        return 1;

    }

    printf("\nToggled letter: %c\n", symbol ^ 32);

    return 0;
}