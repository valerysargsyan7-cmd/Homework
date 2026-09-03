#include <stdio.h>
#include <string.h>

int main(void)
{
    char copy_word[20];
    char copy_word_destination[20];

    printf("\n=== Simple Copy ===\n\n");

    printf("Enter your word: ");

    if(scanf("%19s", copy_word) != 1){

        fprintf(stderr, "[ERROR] Failed to read the word.\n");
        return 1;

    }

    strcpy(copy_word_destination, copy_word);

    size_t length_of_copy_word = strlen(copy_word_destination);

    printf("\n[SUCCESS] Your string: '%s'\n", copy_word_destination);
    printf("[INFO] String length: %zu\n", length_of_copy_word);

    return 0;
}