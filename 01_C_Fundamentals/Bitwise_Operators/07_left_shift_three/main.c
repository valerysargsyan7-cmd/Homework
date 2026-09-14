#include <stdio.h>

int main(void)
{
    unsigned int number = 0;
    const unsigned int shift_count = 3U;

    printf("\nShifting\n");

    printf("\nEnter number: ");

    if(scanf("%u", &number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid unsigned integer.\n");
        return 1;

    }

    if(shift_count >= sizeof(number) * 8U){

        fprintf(stderr, "Error: Shift count is out of range.\n");
        return 1;

    }

    printf("\nResult: %u\n", number << shift_count);

    return 0;
}