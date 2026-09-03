#include <stdio.h>

int main(void)
{
    float x_coordinate = 0.0f;
    float y_coordinate = 0.0f;
    float radius = 0.0f;

    printf("\nCircle and point\n\n");

    printf("Enter X coordinate: ");

    if(scanf("%f", &x_coordinate) != 1){

        fprintf(stderr, "Error: Invalid X coordinate.\n");
        return 1;

    }

    printf("Enter Y coordinate: ");

    if(scanf("%f", &y_coordinate) != 1){

        fprintf(stderr, "Error: Invalid Y coordinate.\n");
        return 1;

    }

    printf("Enter radius: ");

    if(scanf("%f", &radius) != 1){

        fprintf(stderr, "Error: Invalid radius.\n");
        return 1;

    }

    if(radius < 0.0f){

        fprintf(stderr, "Error: Radius cannot be negative.\n");
        return 1;

    }

    if((x_coordinate * x_coordinate) +
       (y_coordinate * y_coordinate) <=
       (radius * radius)){

        printf("\nTrue\n");

    }else{

        printf("\nFalse\n");
    }

    return 0;
}