#include <stdio.h>

int main(void)
{
    int seconds = 0;
    int hours = 0;
    int minutes = 0;
    int remaining_seconds = 0;

    printf("\nTime converting\n\n");

    printf("Enter seconds: ");

    if(scanf("%d", &seconds) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;

    }

    if(seconds < 0){

        fprintf(stderr, "Error: Seconds cannot be negative.\n");
        return 1;

    }

    hours = seconds / 3600;
    minutes = (seconds / 60) % 60;
    remaining_seconds = seconds % 60;

    printf("\n%02d:%02d:%02d\n",
           hours,
           minutes,
           remaining_seconds);

    return 0;
}