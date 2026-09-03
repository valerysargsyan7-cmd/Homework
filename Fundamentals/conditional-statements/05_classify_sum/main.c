#include <stdio.h>

int main(void)
{
    int first_num = 0;
    int second_num = 0;
    int third_num = 0;
    int result = 0;

    printf("\nSum check\n");

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

    result = first_num + second_num + third_num;

    if(result > 100){

        printf("\nLarge sum\n");

    }else if(result < 100){

        printf("\nSmall sum\n");

    }else{

        printf("\nSum is exactly 100\n");
    }

    return 0;
}