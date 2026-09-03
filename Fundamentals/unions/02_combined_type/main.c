#include <stdio.h>

enum TypeChoice
{
    INT,
    CHAR
};

union Value
{
    int i;
    char c;
};

struct Data
{
    enum TypeChoice type;
    union Value value;
};

int main(void)
{
    struct Data data;
    int data_type_input = 0;

    printf("\n=== Combined Type ===\n\n");

    printf("Enter your data type (INT-0, CHAR-1): ");

    if(scanf("%d", &data_type_input) != 1){

        fprintf(stderr, "[ERROR] Invalid data type.\n");
        return 1;

    }

    if(data_type_input < INT || data_type_input > CHAR){

        fprintf(stderr, "[ERROR] Data type must be 0 or 1.\n");
        return 1;

    }

    data.type = (enum TypeChoice)data_type_input;

    if(data.type == CHAR){

        data.value.c = 'A';

        printf(
            "\n[SUCCESS] Your data is: %c\n",
            data.value.c
        );

    }else{

        data.value.i = 100;

        printf(
            "\n[SUCCESS] Your data is: %d\n",
            data.value.i
        );
    }

    return 0;
}