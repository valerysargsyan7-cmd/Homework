#include <stdio.h>

int main(void)
{
    float celsius = 0.0f;
    float fahrenheit = 0.0f;

    printf("\nTemperature conversion\n");

    printf("\nEnter temperature (Celsius): ");

    if(scanf("%f", &celsius) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid temperature.\n");
        return 1;

    }

    fahrenheit = celsius * 1.8f + 32.0f;

    printf("\nTemperature: %.2f Fahrenheit\n", fahrenheit);

    return 0;
}