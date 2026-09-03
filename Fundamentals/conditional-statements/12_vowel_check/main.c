#include <stdio.h>

int main(void)
{
    char letter = '\0';

    printf("\nLetter checking\n");

    printf("\nEnter letter: ");

    if(scanf(" %c", &letter) != 1){

        fprintf(stderr, "Error: Failed to read a character.\n");
        return 1;

    }

    if(letter == 'a' || letter == 'e' || letter == 'i' ||
       letter == 'o' || letter == 'u' ||
       letter == 'A' || letter == 'E' || letter == 'I' ||
       letter == 'O' || letter == 'U'){

        printf("\nVowel\n");

    }else{

        printf("\nNon-vowel\n");
    }

    return 0;
}