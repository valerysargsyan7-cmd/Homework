#include <stdio.h>
int main()
{
    printf("\n\nThe most popular symbol in string\n\n");

    char str_pop[20];

    printf("Enter your string in lowercase: ");

    if(scanf("%19s", str_pop) != 1){

        fprintf(stderr, "[ERROR] Invalid input.\n");
        return 1;

    }

    int letter_count[26] = {0};

    int popular = 0;

    char popular_symbol = '\0';

    for(int i = 0; str_pop[i] != '\0'; i++){

        if(str_pop[i] >= 'a' && str_pop[i] <= 'z'){

            int letter_index = str_pop[i] - 'a';

            letter_count[letter_index]++;

            if(letter_count[letter_index] > popular){

                popular = letter_count[letter_index];
                popular_symbol = str_pop[i];

            }
        }
    }

    if(popular_symbol != '\0'){

        printf("\nMost popular symbol: %c\n", popular_symbol);
        printf("Number of occurrences: %d\n", popular);

    }else{

        printf("\nNo lowercase letters found.\n");

    }

    return 0;
}