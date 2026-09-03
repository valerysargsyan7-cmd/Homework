#include <stdio.h>
#include <string.h>

int main(void)
{
    char palindrome_word[10];
    char reversed_word[10];

    printf("\n=== Palindrome Word ===\n\n");

    printf("Enter your word: ");

    if(scanf("%9s", palindrome_word) != 1){

        fprintf(stderr, "[ERROR] Failed to read the word.\n");
        return 1;

    }

    size_t word_length = strlen(palindrome_word);

    for(size_t i = 0; i < word_length; i++){

        reversed_word[i] =
            palindrome_word[word_length - 1 - i];

    }

    reversed_word[word_length] = '\0';

    if(strcmp(palindrome_word, reversed_word) == 0){

        printf("\n[SUCCESS] YES — the word is a palindrome.\n");

    }else{

        printf("\n[INFO] NO — the word is not a palindrome.\n");

    }

    return 0;
}