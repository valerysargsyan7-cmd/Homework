#include <stdio.h>

int main(void)
{
    int present_year = 0;
    int event_year = 0;
    int difference_of_years = 0;

    printf("\nEvent year count\n");

    printf("\nWrite present year: ");

    if(scanf("%d", &present_year) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid year.\n");
        return 1;

    }

    printf("Write event year: ");

    if(scanf("%d", &event_year) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid year.\n");
        return 1;

    }

    difference_of_years = present_year - event_year;

    printf("\nDifference: %d years\n", difference_of_years);

    return 0;
}