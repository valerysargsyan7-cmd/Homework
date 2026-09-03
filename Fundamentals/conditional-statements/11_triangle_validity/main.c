#include <stdio.h>

int main(void)
{
    int height = 0;
    int width = 0;
    int length = 0;

    printf("\nTriangle building\n");

    printf("\nEnter height: ");

    if(scanf("%d", &height) != 1){

        fprintf(stderr, "Error: Invalid height.\n");
        return 1;

    }

    printf("Enter width: ");

    if(scanf("%d", &width) != 1){

        fprintf(stderr, "Error: Invalid width.\n");
        return 1;

    }

    printf("Enter length: ");

    if(scanf("%d", &length) != 1){

        fprintf(stderr, "Error: Invalid length.\n");
        return 1;

    }

    if(height <= 0 || width <= 0 || length <= 0){

        fprintf(stderr, "Error: Triangle sides must be positive.\n");
        return 1;

    }

    if((long long)height + width > length && (long long)height + length > width && (long long)width + length > height){

        printf("\nSUCCESS\n");

    }else{

        printf("\nUNSUCCESS\n");
    }

    return 0;
}