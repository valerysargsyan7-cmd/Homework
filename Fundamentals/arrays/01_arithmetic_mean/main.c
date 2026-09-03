#include <stdio.h>

int main(void)
{
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum_of_members = 0;
    int number_count = 10;

    printf("\n=== Arithmetic Mean ===\n\n");

    for(int i = 0; i < number_count; i++){

        sum_of_members += numbers[i];

    }

    float mean = (float)sum_of_members / number_count;

    printf("\n[SUCCESS] Arithmetic mean: %.2f\n", mean);

    return 0;
}