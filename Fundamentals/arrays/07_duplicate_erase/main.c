#include <stdio.h>

int main()
{
    printf("\n\nErasing duplicates\n\n");

    int duplicate[10];

    for(int i = 0; i < 10; i++){

        printf("Enter your %dth number: ", i + 1);

        if(scanf("%d", &duplicate[i]) != 1){

            fprintf(stderr, "[ERROR] Invalid input. Please enter an integer.\n");
            return 1;

        }
    }

    int unique_count = 0;

    for(int i = 0; i < 10; i++){

        int is_duplicate = 0;

        for(int j = 0; j < unique_count; j++){

            if(duplicate[i] == duplicate[j]){

                is_duplicate = 1;
                break;

            }
        }

        if(is_duplicate == 0){

            duplicate[unique_count] = duplicate[i];
            unique_count++;

        }
    }

    printf("\nResult: ");

    for(int i = 0; i < unique_count; i++){

        printf("%d ", duplicate[i]);

    }

    printf("\n");

    return 0;
}