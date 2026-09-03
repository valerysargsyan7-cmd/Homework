#include <stdio.h>

int main(void)
{
    char converting_case[20];

    printf("\n=== Lowercase to Uppercase ===\n\n");

    printf("Enter your word in lowercase: ");

    if(scanf("%19s", converting_case) != 1){

        fprintf(stderr, "[ERROR] Failed to read the word.\n");
        return 1;

    }

    for(int i = 0; converting_case[i] != '\0'; i++){

        if(converting_case[i] >= 'a' &&
           converting_case[i] <= 'z'){

            converting_case[i] -= 32;

        }
    }

    printf("\n[SUCCESS] Uppercase word: %s\n", converting_case);

    return 0;
}