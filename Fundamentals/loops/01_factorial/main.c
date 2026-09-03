#include <stdio.h>

int main(void)
{
    int entered_number = 0;
    int factorial = 1;

    printf("\n=== Factorial Calculator ===\n\n");

    printf("Enter your number: ");

    if(scanf("%d", &entered_number) != 1){

        fprintf(stderr, "[ERROR] Invalid input.\n");
        return 1;

    }

    if(entered_number < 0){

        fprintf(stderr, "[ERROR] Factorial is not defined for negative numbers.\n");
        return 1;

    }

    for(int i = 1; i <= entered_number; ++i){

        factorial *= i;

    }

    printf("\n[SUCCESS] Factorial of %d is: %d\n", entered_number, factorial);

    return 0;
}