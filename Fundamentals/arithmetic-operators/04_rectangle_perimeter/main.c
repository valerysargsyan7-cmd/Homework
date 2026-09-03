#include <stdio.h>
#include <limits.h>

int main(void)
{
    int length = 0;
    int width = 0;
    int perimeter = 0;

    printf("\nRectangle perimeter\n");

    printf("\nEnter length: ");

    if(scanf("%d", &length) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("Enter width: ");

    if(scanf("%d", &width) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(length < 0 || width < 0){

        fprintf(stderr, "Error: Length and width cannot be negative.\n");
        return 1;

    }

    if(length > (INT_MAX / 2) - width){

        fprintf(stderr, "Error: Rectangle perimeter is too large.\n");
        return 1;

    }

    perimeter = 2 * (length + width);

    printf("\nPerimeter: %d\n", perimeter);

    return 0;
}