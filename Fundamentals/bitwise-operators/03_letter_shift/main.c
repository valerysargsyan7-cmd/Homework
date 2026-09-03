#include <stdio.h>

int main(void)
{
    char letter = '\0';

    printf("\nLetter shift\n");

    printf("\nEnter your letter: ");

    if(scanf(" %c", &letter) != 1){

        fprintf(stderr, "Error: Failed to read a character.\n");
        return 1;

    }

    if((letter < 'a' || letter > 'z') &&
       (letter < 'A' || letter > 'Z')){

        fprintf(stderr, "Error: Please enter an English letter.\n");
        return 1;

    }

    if(letter == 'a' || letter == 'A'){

        fprintf(stderr, "Error: Cannot shift before the first letter.\n");
        return 1;

    }

    printf("\nPrevious letter: %c\n", letter - 1);

    return 0;
}