#include <stdio.h>

int main(void)
{
    float float_value = 1.0f / 3.0f;
    double double_value = 1.0 / 3.0;

    printf("\nIEEE 754 precision\n");

    printf("\nFloat value:  %.15f\n", float_value);
    printf("Double value: %.15f\n", double_value);

    return 0;
}