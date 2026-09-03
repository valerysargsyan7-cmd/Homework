#include <stdio.h>

int main(void)
{
    int fizz_buzz_number = 0;

    printf("\nFizzBuzz\n\n");

    printf("\nEnter your FizzBuzz number: ");

    if(scanf("%d", &fizz_buzz_number) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;

    }

    if(fizz_buzz_number % 3 == 0 &&
       fizz_buzz_number % 5 == 0){

        printf("\nFizzBuzz\n");

    }else if(fizz_buzz_number % 3 == 0){

        printf("\nFizz\n");

    }else if(fizz_buzz_number % 5 == 0){

        printf("\nBuzz\n");

    }else{

        printf("\n%d\n", fizz_buzz_number);
    }

    return 0;
}