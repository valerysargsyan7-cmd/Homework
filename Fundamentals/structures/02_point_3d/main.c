#include <stdio.h>

typedef struct
{
    float x;
    float y;
    float z;
    
} Point3D;

int main(void)
{
    Point3D point;

    printf("\n=== Point in 3D ===\n\n");

    printf("Enter coordinate X: ");

    if(scanf("%f", &point.x) != 1){

        fprintf(stderr, "[ERROR] Invalid X coordinate.\n");
        return 1;

    }

    printf("Enter coordinate Y: ");

    if(scanf("%f", &point.y) != 1){

        fprintf(stderr, "[ERROR] Invalid Y coordinate.\n");
        return 1;

    }

    printf("Enter coordinate Z: ");

    if(scanf("%f", &point.z) != 1){

        fprintf(stderr, "[ERROR] Invalid Z coordinate.\n");
        return 1;

    }

    if(point.x == 0.0f &&
       point.y == 0.0f &&
       point.z == 0.0f){

        printf("\n[INFO] Origin point.\n");

    }else{

        printf(
            "\n[SUCCESS] Point: %.2f : %.2f : %.2f\n",
            point.x,
            point.y,
            point.z
        );
    }

    return 0;
}