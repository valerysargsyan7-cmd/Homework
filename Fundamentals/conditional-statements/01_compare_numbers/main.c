#include <stdio.h>

int main(void)
{
    int first_num = 0;
    int second_num = 0;

    printf("\nCompare two numbers\n");

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

    if(first_num == second_num){

        printf("\nNumbers are equal\n");

    }else{

        printf("\nNumbers are different\n");
    }

    return 0;
}