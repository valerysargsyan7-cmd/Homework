#include <stdio.h>

int main(void)
{
    char vowel_word[20];
    int vowel_count = 0;

    printf("\n=== Vowel Count ===\n\n");

    printf("Enter your word: ");

    if(scanf("%19s", vowel_word) != 1){

        fprintf(stderr, "[ERROR] Failed to read the word.\n");
        return 1;

    }

    for(int i = 0; vowel_word[i] != '\0'; i++){

        if(vowel_word[i] == 'a' ||
           vowel_word[i] == 'e' ||
           vowel_word[i] == 'i' ||
           vowel_word[i] == 'o' ||
           vowel_word[i] == 'u'){

            vowel_count++;

        }
    }

    printf(
        "\n[SUCCESS] Number of vowels: %d\n",
        vowel_count
    );

    return 0;
}