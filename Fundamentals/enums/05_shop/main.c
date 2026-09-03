#include <stdio.h>

enum Category{

    FOOD,
    ELECTRONICS,
    CLOTHING

};

struct Product{

    char product_name[20];
    float product_price;
    enum Category cat;

};

int main()
{
    printf("\n\nShop\n\n");

    struct Product products[5];

    for(int i = 0; i < 5; i++){

        int category_choice = 0;

        printf("Enter category 0 - FOOD, 1 - ELECTRONICS, 2 - CLOTHING: ");

        if(scanf("%d", &category_choice) != 1){

            fprintf(stderr, "[ERROR] Invalid category input.\n");
            return 1;

        }

        if(category_choice < 0 || category_choice > 2){

            fprintf(stderr, "[ERROR] Invalid category. Please enter 0, 1 or 2.\n");
            i--;
            continue;

        }

        products[i].cat = category_choice;

        printf("Enter product name: ");

        if(scanf("%19s", products[i].product_name) != 1){

            fprintf(stderr, "[ERROR] Invalid product name.\n");
            return 1;

        }

        printf("Enter product price: ");

        if(scanf("%f", &products[i].product_price) != 1){

            fprintf(stderr, "[ERROR] Invalid product price. Please enter a number.\n");
            return 1;

        }

    }

    printf("\nElectronics products:\n");

    for(int i = 0; i < 5; i++){

        if(products[i].cat == ELECTRONICS){

            printf("%s - %.2f\n",
                   products[i].product_name,
                   products[i].product_price);

        }
    }

    printf("\nFood products:\n");

    for(int i = 0; i < 5; i++){

        if(products[i].cat == FOOD){

            printf("%s - %.2f\n",
                   products[i].product_name,
                   products[i].product_price);

        }
    }

    printf("\nClothing products:\n");

    for(int i = 0; i < 5; i++){

        if(products[i].cat == CLOTHING){

            printf("%s - %.2f\n",
                   products[i].product_name,
                   products[i].product_price);

        }
    }


    return 0;
}