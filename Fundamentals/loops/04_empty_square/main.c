#include <stdio.h>

int main(void)
{
    int quantity = 0;
    char square_material = '\0';

    printf("\n=== Empty Square ===\n\n");

    printf("Enter square size: ");

    if(scanf("%d", &quantity) != 1){

        fprintf(stderr, "[ERROR] Invalid square size.\n");
        return 1;

    }

    if(quantity <= 0){

        fprintf(stderr, "[ERROR] Square size must be positive.\n");
        return 1;

    }

    printf("Enter symbol for the square: ");

    if(scanf(" %c", &square_material) != 1){

        fprintf(stderr, "[ERROR] Failed to read square symbol.\n");
        return 1;

    }

    for(int i = 0; i < quantity; i++){

        for(int j = 0; j < quantity; j++){

            if(i == 0 ||
               i == quantity - 1 ||
               j == 0 ||
               j == quantity - 1){

                printf("%c", square_material);

            }else{

                printf(" ");

            }
        }

        printf("\n");
    }

    return 0;
}