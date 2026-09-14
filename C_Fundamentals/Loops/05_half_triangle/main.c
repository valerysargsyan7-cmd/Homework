#include <stdio.h>

int main()
{
    printf("\n\nHalf triangle\n\n");

    int quantity_triangle = 0;

    printf("Enter quantity: ");

    if(scanf("%d", &quantity_triangle) != 1){

        fprintf(stderr, "[ERROR] Invalid quantity input. Please enter an integer.\n");
        return 1;

    }

    if(quantity_triangle <= 0){

        fprintf(stderr, "[ERROR] Quantity must be greater than zero.\n");
        return 1;

    }

    char triangle_material = 0;

    printf("Enter symbol for building triangle: ");

    if(scanf(" %c", &triangle_material) != 1){

        fprintf(stderr, "[ERROR] Invalid symbol input.\n");
        return 1;

    }

    for(int i = 1; i <= quantity_triangle; i++){

        for(int j = 1; j <= quantity_triangle; j++){

            if(j <= quantity_triangle - i){

                printf(" ");

            }else{

                printf("%c", triangle_material);

            }
        }

        printf("\n");
    }

    return 0;
}