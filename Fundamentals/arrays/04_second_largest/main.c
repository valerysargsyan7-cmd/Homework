#include <stdio.h>

int main(void)
{
    int numbers[10];
    int max;
    int second_max;

    printf("\n=== Second Largest Element ===\n\n");

    for(int i = 0; i < 10; i++){

        printf("Enter element %d: ", i + 1);

        if(scanf("%d", &numbers[i]) != 1){

            fprintf(stderr, "[ERROR] Invalid number.\n");
            return 1;

        }
    }

    if(numbers[0] > numbers[1]){

        max = numbers[0];
        second_max = numbers[1];

    }else{

        max = numbers[1];
        second_max = numbers[0];

    }

    for(int i = 2; i < 10; i++){

        if(numbers[i] > max){

            second_max = max;
            max = numbers[i];

        }else if(numbers[i] > second_max &&
                 numbers[i] != max){

            second_max = numbers[i];

        }
    }

    if(max == second_max){

        fprintf(stderr, "[ERROR] There is no distinct second-largest element.\n");
        return 1;

    }

    printf("\n[SUCCESS] Second largest number: %d\n", second_max);

    return 0;
}