#include <stdio.h>

int main(void)
{
    long long tomato_price = 0;
    long long potato_price = 0;
    long long banana_price = 0;
    long long discount_percent = 0;

    long long discounted_tomato_price = 0;
    long long discounted_potato_price = 0;
    long long discounted_banana_price = 0;

    printf("\nShop discounts\n");

    printf("\nEnter tomato price: ");

    if(scanf("%lld", &tomato_price) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid price.\n");
        return 1;

    }

    printf("Enter potato price: ");

    if(scanf("%lld", &potato_price) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid price.\n");
        return 1;

    }

    printf("Enter banana price: ");

    if(scanf("%lld", &banana_price) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid price.\n");
        return 1;

    }

    if(tomato_price < 0 || potato_price < 0 || banana_price < 0){

        fprintf(stderr, "Error: Prices cannot be negative.\n");
        return 1;

    }

    printf("Enter discount percent (0 - 100): ");

    if(scanf("%lld", &discount_percent) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid percentage.\n");
        return 1;

    }

    if(discount_percent < 0 || discount_percent > 100){

        fprintf(stderr, "Error: Discount must be between 0 and 100.\n");
        return 1;

    }

    discounted_tomato_price = tomato_price - (tomato_price * discount_percent / 100);
    discounted_potato_price = potato_price - (potato_price * discount_percent / 100);
    discounted_banana_price = banana_price - (banana_price * discount_percent / 100);

    printf("\nTomato price with %lld%% discount: %lld\n", discount_percent, discounted_tomato_price);
    printf("Potato price with %lld%% discount: %lld\n", discount_percent, discounted_potato_price);
    printf("Banana price with %lld%% discount: %lld\n", discount_percent, discounted_banana_price);

    return 0;
}