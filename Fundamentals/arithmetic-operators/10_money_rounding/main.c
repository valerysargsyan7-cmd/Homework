#include <stdio.h>

int main(void)
{
    double money = 0.0;
    long long rounded = 0;

    printf("\nShop money\n");

    printf("\nEnter money: ");

    if(scanf("%lf", &money) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid amount.\n");
        return 1;

    }

    if(money < 0.0){

        fprintf(stderr, "Error: Money cannot be negative.\n");
        return 1;

    }

    rounded = (long long)(money + 0.5);

    printf("\nRounded: %lld\n", rounded);

    return 0;
}