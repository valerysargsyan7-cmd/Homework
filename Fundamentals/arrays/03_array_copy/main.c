#include <stdio.h>

int main(void)
{
    char source_array[5];
    char destination_array[5];

    printf("\n=== Array Copy ===\n\n");

    for(int i = 0; i < 5; i++){

        printf("Enter value %d: ", i);

        if(scanf(" %c", &source_array[i]) != 1){

            fprintf(stderr, "[ERROR] Failed to read character.\n");
            return 1;

        }
    }

    for(int i = 0; i < 5; i++){

        destination_array[i] = source_array[i];

    }

    printf("\nCopied values:\n");

    for(int i = 0; i < 5; i++){

        printf("\n[INFO] Value %d: %c\n", i, destination_array[i]);

    }

    return 0;
}