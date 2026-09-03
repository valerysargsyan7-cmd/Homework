#include <stdio.h>

int main(void)
{
    int user_number = 0;

    printf("\n=== Sum of Digits ===\n\n");

    while(1){

        printf("Enter your number (0 to exit): ");

        if(scanf("%d", &user_number) != 1){

            fprintf(stderr, "[ERROR] Invalid input.\n");
            return 1;

        }

        if(user_number == 0){

            printf("\n[INFO] Goodbye!\n");
            break;

        }

        int number = user_number;

        if(number < 0){

            number = -number;

        }

        int hundred = number / 100;
        int ten = (number / 10) % 10;
        int last_digit = number % 10;

        printf(
            "\n[SUCCESS] %d + %d + %d = %d\n",
            hundred,
            ten,
            last_digit,
            hundred + ten + last_digit
        );
    }

    return 0;
}