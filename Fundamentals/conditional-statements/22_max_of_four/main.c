#include <stdio.h>

int main(void)
{
    int first_number = 0;
    int second_number = 0;
    int third_number = 0;
    int fourth_number = 0;
    int maximum = 0;

    printf("\nMaximum of 4\n\n");

    printf("Enter first number: ");

    if(scanf("%d", &first_number) != 1){

        fprintf(stderr, "Error: Invalid input.\n");
        return 1;

    }

    printf("Enter second number: ");

    if(scanf("%d", &second_number) != 1){

        fprintf(stderr, "Error: Invalid input.\n");
        return 1;

    }

    printf("Enter third number: ");

    if(scanf("%d", &third_number) != 1){

        fprintf(stderr, "Error: Invalid input.\n");
        return 1;

    }

    printf("Enter fourth number: ");

    if(scanf("%d", &fourth_number) != 1){

        fprintf(stderr, "Error: Invalid input.\n");
        return 1;

    }

    maximum = first_number;

    if(second_number > maximum){

        maximum = second_number;
    }

    if(third_number > maximum){

        maximum = third_number;
    }

    if(fourth_number > maximum){

        maximum = fourth_number;
    }

    printf("\nMaximum: %d\n", maximum);

    return 0;
}