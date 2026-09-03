#include <stdio.h>

int main(void)
{
    int month_number = 0;

    printf("\nMonth days\n\n");

    printf("Enter month number: ");

    if(scanf("%d", &month_number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;

    }

    if(month_number < 1 || month_number > 12){

        printf("\nINVALID MONTH\n");

    }else if(month_number == 2){

        printf("\nDays: 28\n");

    }else if(month_number == 4 ||
             month_number == 6 ||
             month_number == 9 ||
             month_number == 11){

        printf("\nDays: 30\n");

    }else{

        printf("\nDays: 31\n");
    }

    return 0;
}