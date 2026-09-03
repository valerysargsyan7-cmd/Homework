#include <stdio.h>

int main(void)
{
    int number = 0;

    printf("\nSumming number members\n\n");

    printf("\nEnter a three-digit number: ");

    if(scanf("%d", &number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;

    }

    if(number < 100 || number > 999){

        fprintf(stderr, "Error: Number must contain exactly three digits.\n");
        return 1;

    }

    int hundred_part = number / 100;
    int ten_part = (number / 10) % 10;
    int one_part = number % 10;
    int number_members_sum = hundred_part + ten_part + one_part;

    printf("\nSum of members: %d\n", number_members_sum);

    return 0;
}