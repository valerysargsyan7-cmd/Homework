#include <stdio.h>

int main(void)
{
    char string[20];
    int count = 0;

    printf("\n=== String Length ===\n\n");

    printf("Enter your word: ");

    if(scanf("%19s", string) != 1){

        fprintf(stderr, "[ERROR] Failed to read the string.\n");
        return 1;

    }

    for(int i = 0; string[i] != '\0'; i++){

        count++;

    }

    printf("\n[SUCCESS] String length: %d\n", count);

    return 0;
}