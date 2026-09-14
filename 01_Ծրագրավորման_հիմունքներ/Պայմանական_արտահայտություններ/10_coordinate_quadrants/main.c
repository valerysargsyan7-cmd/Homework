#include <stdio.h>

int main(void)
{
    float x_coordinate = 0.0f;
    float y_coordinate = 0.0f;

    printf("\nCalculating coordinates\n");

    printf("\nEnter X: ");

    if(scanf("%f", &x_coordinate) != 1){

        fprintf(stderr, "Error: Invalid X coordinate.\n");
        return 1;

    }

    printf("Enter Y: ");

    if(scanf("%f", &y_coordinate) != 1){

        fprintf(stderr, "Error: Invalid Y coordinate.\n");
        return 1;

    }

    if(x_coordinate > 0.0f && y_coordinate > 0.0f){

        printf("\nYou are in I quadrant\n");

    }else if(x_coordinate < 0.0f && y_coordinate > 0.0f){

        printf("\nYou are in II quadrant\n");

    }else if(x_coordinate < 0.0f && y_coordinate < 0.0f){

        printf("\nYou are in III quadrant\n");

    }else if(x_coordinate > 0.0f && y_coordinate < 0.0f){

        printf("\nYou are in IV quadrant\n");

    }else if(x_coordinate == 0.0f && y_coordinate == 0.0f){

        printf("\nYou are at the origin\n");

    }else if(x_coordinate == 0.0f){

        printf("\nYou are on the Y axis\n");

    }else{

        printf("\nYou are on the X axis\n");
    }

    return 0;
}