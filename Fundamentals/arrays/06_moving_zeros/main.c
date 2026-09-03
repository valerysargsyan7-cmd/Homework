#include <stdio.h>

int main(void)
{
    printf("\n\nMoving zeros\n\n");

    int arr_with_zeros[10];

    for(int i = 0; i < 10; i++){

        printf("Enter your %dth number: ", i + 1);

        if (scanf("%d", &arr_with_zeros[i]) != 1) {

            fprintf(stderr, "\n[ERROR] Invalid input. Please enter a valid integer.\n");
            return 1;

        }
    }

    int start_point = 0;

    for(int i = 0; i < 10; i++){

        if(arr_with_zeros[i] != 0){

            arr_with_zeros[start_point] = arr_with_zeros[i];
            start_point++;

        }
    }

    while(start_point < 10){

        arr_with_zeros[start_point] = 0;
        start_point++;

    }

    printf("\nResult:\n");

    for(int i = 0; i < 10; i++){

        printf("%d ", arr_with_zeros[i]);
        
    }

    printf("\n");

    return 0;
}