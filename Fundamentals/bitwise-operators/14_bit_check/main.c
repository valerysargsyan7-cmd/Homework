#include <stdio.h>

int main(void)
{
    int number = 0;
    int third_bit = 0;

    printf("\nBit check\n\n");

    printf("Enter your number: ");

    if(scanf("%d", &number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;

    }

    third_bit = number & 8;

    if(third_bit != 0){

        printf("\nThird bit is one\n");

    }else{

        printf("\nThird bit is zero\n");
    }

    return 0;
}