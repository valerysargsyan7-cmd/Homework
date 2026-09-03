#include <stdio.h>
#include <string.h>

int main()
{
    printf("\n\nReversing string\n\n");

    char reversing_string[20];

    printf("Enter your string: ");

   if(scanf("%19s", reversing_string) != 1){ 

        fprintf(stderr, "[ERROR] Invalid input.\n"); 
        return 1; 

    }

    char reversed_string[20];

    int string_length = strlen(reversing_string);

    for(int i = 0; i < string_length; i++){

        reversed_string[i] = reversing_string[string_length - 1 - i];
    }

    reversed_string[string_length] = '\0';

    printf("\nReversed: %s\n", reversed_string);

    return 0;
}

