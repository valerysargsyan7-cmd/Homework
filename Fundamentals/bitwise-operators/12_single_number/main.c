#include <stdio.h>

int main(void)
{
    int first_number = 0;
    int second_number = 0;
    int third_number = 0;

    while(1){

        printf("\nSingle number\n\n");

        printf("Enter your first number: ");

        if(scanf("%d", &first_number) != 1){

            fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
            return 1;

        }

        printf("Enter your second number: ");

        if(scanf("%d", &second_number) != 1){

            fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
            return 1;

        }

        printf("Enter your third number: ");

        if(scanf("%d", &third_number) != 1){

            fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
            return 1;

        }

        if((first_number == second_number &&
            first_number != third_number) ||
           (first_number == third_number &&
            first_number != second_number) ||
           (second_number == third_number &&
            second_number != first_number)){

            int single_number = first_number ^ second_number ^ third_number;

            printf("\nSingle number is: %d\n", single_number);
            break;

        }else{

            printf("\nWrong, please try again!\n");
        }
    }

    return 0;
}