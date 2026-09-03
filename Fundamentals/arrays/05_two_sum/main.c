#include <stdio.h>

int main(void)
{
    int numbers[10];
    int target = 0;
    int pair_found = 0;

    printf("\n=== Two Sum ===\n\n");

    printf("Enter target number: ");

    if(scanf("%d", &target) != 1){

        fprintf(stderr, "[ERROR] Invalid target.\n");
        return 1;

    }

    for(int i = 0; i < 10; i++){

        printf("Enter element %d: ", i + 1);

        if(scanf("%d", &numbers[i]) != 1){

            fprintf(stderr, "[ERROR] Invalid array element.\n");
            return 1;

        }
    }

    printf("\n");

    for(int i = 0; i < 10; i++){

        for(int j = i + 1; j < 10; j++){

            if(numbers[i] + numbers[j] == target){

                printf(
                    "\n[SUCCESS] Pair found at indexes: %d and %d\n",
                    i,
                    j
                );

                pair_found = 1;
            }
        }
    }

    if(pair_found == 0){

        printf("\n[INFO] No pair found.\n");

    }

    return 0;
}