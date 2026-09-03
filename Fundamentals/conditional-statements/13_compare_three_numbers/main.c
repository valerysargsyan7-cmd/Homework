#include <stdio.h>

int main(void)
{
    int first_num = 0;
    int second_num = 0;
    int third_num = 0;
    int max = 0;

    printf("\nComparing numbers\n");

    printf("\nEnter first number: ");

    if(scanf("%d", &first_num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("Enter second number: ");

    if(scanf("%d", &second_num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("Enter third number: ");

    if(scanf("%d", &third_num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    max = first_num;

    if(second_num > max){

        max = second_num;
    }

    if(third_num > max){

        max = third_num;
    }

    printf("\nMaximum: %d\n", max);

    return 0;
}