#include <stdio.h>

int main(void)
{
    int checking_number = 0;

    printf("\nThree / four / none\n\n");

    printf("Enter your number: ");

    if(scanf("%d", &checking_number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;

    }

    if(checking_number % 3 == 0 && checking_number % 4 == 0){

        printf("\nPerfect\n");

    }else if(checking_number % 3 == 0){

        printf("\nThree\n");

    }else if(checking_number % 4 == 0){

        printf("\nFour\n");

    }else{

        printf("\n%d\n", checking_number);
    }

    return 0;
}