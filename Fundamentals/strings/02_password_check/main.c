#include <stdio.h>
#include <string.h>

int main(void)
{
    char user_password[20];
    const char password[] = "Password";

    printf("\n=== Password Check ===\n\n");

    printf("Enter password: ");

    if(scanf("%19s", user_password) != 1){

        fprintf(stderr, "[ERROR] Failed to read password.\n");
        return 1;

    }

    if(strcmp(user_password, password) == 0){

        printf("\n[SUCCESS] ACCESS GRANTED\n");

    }else{

        printf("\n[ERROR] ACCESS DENIED\n");

    }

    return 0;
}