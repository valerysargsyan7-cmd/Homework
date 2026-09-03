#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int age = 0;
    bool eligible = false;

    printf("\nPresidential eligibility\n\n");

    printf("Enter your age: ");

    if(scanf("%d", &age) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;

    }

    if(age < 0){

        fprintf(stderr, "Error: Age cannot be negative.\n");
        return 1;

    }

    eligible = age >= 25;

    printf("\nEligible: %d\n", eligible);

    return 0;
}