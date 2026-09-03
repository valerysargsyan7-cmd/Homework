#include <stdio.h>

int main(void)
{
    char user_letter = '\0';

    printf("\nLowercase or uppercase\n");

    printf("\nEnter your letter: ");

    if(scanf(" %c", &user_letter) != 1){

        fprintf(stderr, "Error: Failed to read a character.\n");
        return 1;

    }

    if(user_letter >= 'A' && user_letter <= 'Z'){

        user_letter = user_letter | 32;

    }else if(user_letter < 'a' || user_letter > 'z'){

        fprintf(stderr, "Error: Please enter an English letter.\n");
        return 1;
    }

    printf("\nLOWERCASE: %c\n", user_letter);

    return 0;
}