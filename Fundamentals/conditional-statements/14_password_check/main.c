#include <stdio.h>

int main(void)
{
    const int password = 4554;
    int user_try = 0;

    printf("\nPassword checking\n");

    printf("\nEnter password: ");

    if(scanf("%d", &user_try) != 1){

        fprintf(stderr, "Error: Invalid password input.\n");
        return 1;

    }

    if(user_try == password){

        printf("\nACCESS GRANTED\n");

    }else{

        printf("\nACCESS DENIED\n");
    }

    return 0;
}