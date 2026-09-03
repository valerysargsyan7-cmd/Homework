#include <stdio.h>

int main(void)
{
    int first_num = 0;
    int second_num = 0;

    printf("\nFind maximum\n");

    printf("\nEnter your first number: ");

    if(scanf("%d", &first_num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("Enter your second number: ");

    if(scanf("%d", &second_num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(first_num > second_num){

        printf("\nFirst number is bigger than second\n");

    }else if(second_num > first_num){

        printf("\nSecond number is bigger than first\n");

    }else{

        printf("\nNumbers are equal\n");
    }

    return 0;
}