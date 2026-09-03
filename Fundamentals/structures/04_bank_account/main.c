#include <stdio.h>

struct BankAccount
{
    float balance;
};

int main(void)
{
    struct BankAccount account;
    float money_to_take = 0.0f;

    printf("\n=== Bank Account ===\n\n");

    printf("Enter your balance: ");

    if(scanf("%f", &account.balance) != 1){

        fprintf(stderr, "[ERROR] Invalid balance.\n");
        return 1;

    }

    if(account.balance < 0.0f){

        fprintf(stderr, "[ERROR] Balance cannot be negative.\n");
        return 1;

    }

    while(1){

        printf("\nHow much money do you want to take? (0 to exit): ");

        if(scanf("%f", &money_to_take) != 1){

            fprintf(stderr, "[ERROR] Invalid amount.\n");
            return 1;

        }

        if(money_to_take == 0.0f){

            printf("\n[INFO] Operation finished.\n");
            break;

        }

        if(money_to_take < 0.0f){

            fprintf(stderr, "[ERROR] Amount cannot be negative.\n");
            continue;

        }

        if(money_to_take <= account.balance){

            account.balance -= money_to_take;

            printf(
                "\n[SUCCESS] Withdrawn: %.2f\n"
                "[INFO] Remaining balance: %.2f\n",
                money_to_take,
                account.balance
            );

        }else{

            printf("[ERROR] Insufficient funds.\n");
            break;
        }
    }

    return 0;
}