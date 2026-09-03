#include <stdio.h>

int main(void) {

    unsigned int number = 0;
    unsigned int shift_count = 0;
    const unsigned int max_bits = sizeof(number) * 8U;

    printf("\nLeft shifting\n");

    printf("Enter your number: ");

    if(scanf("%u", &number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid unsigned integer.\n");
        return 1;

    }

    printf("Enter shift count (0 - %u): ", max_bits - 1);

    if(scanf("%u", &shift_count) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid unsigned integer.\n");
        return 1;

    }

    if(shift_count >= max_bits){

        fprintf(stderr, "Error: Shift count is out of range.\n");
        return 1;

    }

    printf("Result: %u\n", number << shift_count);

    return 0;
}