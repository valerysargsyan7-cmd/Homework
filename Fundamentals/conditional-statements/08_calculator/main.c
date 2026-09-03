#include <stdio.h>

int main(void)
{
    int first_num = 0;
    int second_num = 0;
    char operator = '\0';

    printf("\nCalculator\n");

    printf("\nEnter first number: ");

    if(scanf("%d", &first_num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("Enter operator (+ - * /): ");

    if(scanf(" %c", &operator) != 1){

        fprintf(stderr, "Error: Invalid operator input.\n");
        return 1;

    }

    printf("Enter second number: ");

    if(scanf("%d", &second_num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(operator == '+'){

        printf("\nResult: %d\n", first_num + second_num);

    }else if(operator == '-'){

        printf("\nResult: %d\n", first_num - second_num);

    }else if(operator == '*'){

        printf("\nResult: %d\n", first_num * second_num);

    }else if(operator == '/'){

        if(second_num == 0){

            fprintf(stderr, "Error: Division by zero is not allowed.\n");
            return 1;

        }

        printf("\nResult: %d\n", first_num / second_num);

    }else{

        fprintf(stderr, "Error: Invalid operator. Use +, -, * or /.\n");
        return 1;
    }

    return 0;
}