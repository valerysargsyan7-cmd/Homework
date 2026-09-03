#include <stdio.h>

int main(void)
{
    int first_num = 0;
    int second_num = 0;

    printf("\nXOR swapping\n");

    printf("\nEnter number of a: ");

    if(scanf("%d", &first_num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("Enter number of b: ");

    if(scanf("%d", &second_num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    first_num = first_num ^ second_num;
    second_num = first_num ^ second_num;
    first_num = first_num ^ second_num;

    printf("\na = %d, b = %d\n", first_num, second_num);

    return 0;
}