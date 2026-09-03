#include <stdio.h>

int main(void)
{
    int current_number = 0;
    int divisor_count = 0;

    printf("\n=== Prime Number Check ===\n\n");

    printf("Enter your number: ");

    if(scanf("%d", &current_number) != 1){

        fprintf(stderr, "[ERROR] Invalid input.\n");
        return 1;

    }

    if(current_number < 2){

        printf("\n[INFO] Number is not prime.\n");
        return 0;

    }

    for(int i = 1; i <= current_number; i++){

        if(current_number % i == 0){

            divisor_count++;

        }
    }

    if(divisor_count == 2){

        printf("\n[SUCCESS] Number is prime.\n");

    }else{

        printf("\n[INFO] Number is not prime.\n");

    }

    return 0;
}