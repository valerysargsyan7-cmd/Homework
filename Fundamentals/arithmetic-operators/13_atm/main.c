#include <stdio.h>

int main(void)
{
    int money_requested = 0;

    printf("\nATM\n");

    printf("\nHow much money do you want?: ");

    if(scanf("%d", &money_requested) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;

    }

    if(money_requested < 0){

        fprintf(stderr, "Error: Requested money cannot be negative.\n");
        return 1;

    }

    int avetik_count = money_requested / 10000;
    money_requested %= 10000;

    int tumanyan_count = money_requested / 5000;
    money_requested %= 5000;

    int charents_exishe_count = money_requested / 1000;
    money_requested %= 1000;

    if(money_requested != 0){

        printf("Error: Amount must be divisible by 1000.\n");
        return 1;

    }

    printf(
        "\n%d times 10000, %d times 5000, %d times 1000\n",
        avetik_count,
        tumanyan_count,
        charents_exishe_count
    );

    return 0;
}