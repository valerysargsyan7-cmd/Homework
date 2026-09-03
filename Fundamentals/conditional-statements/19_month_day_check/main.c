#include <stdio.h>

int main(void)
{
    int day = 0;
    int month = 0;

    printf("\nChecking month day combination\n\n");

    printf("Enter day: ");

    if(scanf("%d", &day) != 1){

        fprintf(stderr, "Error: Invalid day.\n");
        return 1;

    }

    printf("Enter month: ");

    if(scanf("%d", &month) != 1){

        fprintf(stderr, "Error: Invalid month.\n");
        return 1;

    }

    if(month < 1 || month > 12){

        printf("\nINVALID\n");

    }else if(month == 2){

        if(day >= 1 && day <= 28){

            printf("\nVALID\n");

        }else{

            printf("\nINVALID\n");
        }

    }else if(month == 4 || month == 6 ||
             month == 9 || month == 11){

        if(day >= 1 && day <= 30){

            printf("\nVALID\n");

        }else{

            printf("\nINVALID\n");
        }

    }else{

        if(day >= 1 && day <= 31){

            printf("\nVALID\n");

        }else{

            printf("\nINVALID\n");
        }
    }

    return 0;
}