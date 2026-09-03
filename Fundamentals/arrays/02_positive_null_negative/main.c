#include <stdio.h>

int main(void)
{
    int numbers[10];

    printf("\n=== Positive / Zero / Negative ===\n\n");

    for(int i = 0; i < 10; i++){

        printf("Enter number %d: ", i + 1);

        if(scanf("%d", &numbers[i]) != 1){

            fprintf(stderr, "[ERROR] Invalid number.\n");
            return 1;

        }

        if(numbers[i] > 0){

            printf("\n[INFO] %d is positive.\n", numbers[i]);

        }else if(numbers[i] == 0){

            printf("\n[INFO] %d is zero.\n", numbers[i]);

        }else{

            printf("\n[INFO] %d is negative.\n", numbers[i]);

        }
    }

    return 0;
}