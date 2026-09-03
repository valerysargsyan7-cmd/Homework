#include <stdio.h>

int main(void)
{
    int secret_data = 0;
    int key = 0;
    int cipher = 0;
    int decrypted_data = 0;

    printf("\nXOR cipher\n");

    printf("\nEnter secret data: ");

    if(scanf("%d", &secret_data) != 1){

        fprintf(stderr, "Error: Invalid secret data.\n");
        return 1;

    }

    printf("Enter key: ");

    if(scanf("%d", &key) != 1){

        fprintf(stderr, "Error: Invalid key.\n");
        return 1;

    }

    cipher = secret_data ^ key;
    decrypted_data = cipher ^ key;

    printf("\nEncrypted data: %d\n", cipher);
    printf("Decrypted data: %d\n", decrypted_data);

    return 0;
}