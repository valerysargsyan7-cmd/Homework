#include <stdio.h>

int main(void)
{
    int checking_number = 0;

    printf("\nChecking power of two\n\n");

    printf("Enter your number: ");

    if(scanf("%d", &checking_number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;

    }

    if(checking_number > 0 &&
       (checking_number & (checking_number - 1)) == 0){

        printf("\nTRUE\n");

    }else{

        printf("\nFALSE\n");
    }

    return 0;
}