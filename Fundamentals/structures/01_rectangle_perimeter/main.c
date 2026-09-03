#include <stdio.h>

struct Rectangle
{
    int width;
    int height;
};

int main(void)
{
    struct Rectangle rectangle;

    printf("\n=== Rectangle Perimeter ===\n\n");

    printf("Enter width: ");

    if(scanf("%d", &rectangle.width) != 1){

        fprintf(stderr, "[ERROR] Invalid width.\n");
        return 1;

    }

    printf("Enter height: ");

    if(scanf("%d", &rectangle.height) != 1){

        fprintf(stderr, "[ERROR] Invalid height.\n");
        return 1;

    }

    if(rectangle.width <= 0 || rectangle.height <= 0){

        fprintf(stderr, "[ERROR] Width and height must be positive.\n");
        return 1;

    }

    if(rectangle.width == rectangle.height){

        printf("\n[INFO] This rectangle is a square.\n");

    }else{

        printf(
            "\n[SUCCESS] Perimeter is: %d\n",
            2 * (rectangle.width + rectangle.height)
        );
    }

    return 0;
}