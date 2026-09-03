#include <stdio.h>

enum DataType
{
    INT,
    FLOAT
};

union IntOrFloat
{
    int integer;
    float floating_point;
};

struct Variable
{
    enum DataType type;
    union IntOrFloat value;
};

int main(void)
{
    struct Variable variables[5];
    float sum_of_values = 0.0f;
    int type_choice = 0;

    printf("\n=== Smart Variable ===\n\n");

    for(int i = 0; i < 5; i++){

        printf(
            "Variable %d/5\n"
            "  0 - INT\n"
            "  1 - FLOAT\n"
            "Enter type: ",
            i + 1
        );

        if(scanf("%d", &type_choice) != 1){

            fprintf(stderr, "[ERROR] Invalid type input.\n");
            return 1;

        }

        if(type_choice == INT){

            variables[i].type = INT;

            printf("Enter INT value: ");

            if(scanf("%d", &variables[i].value.integer) != 1){

                fprintf(stderr, "[ERROR] Invalid integer value.\n");
                return 1;

            }

            sum_of_values += variables[i].value.integer;

        }else if(type_choice == FLOAT){

            variables[i].type = FLOAT;

            printf("Enter FLOAT value: ");

            if(scanf("%f", &variables[i].value.floating_point) != 1){

                fprintf(stderr, "[ERROR] Invalid floating-point value.\n");
                return 1;

            }

            sum_of_values += variables[i].value.floating_point;

        }else{

            fprintf(stderr, "[ERROR] Type must be 0 or 1.\n");
            return 1;
        }
    }

    printf("\n[SUCCESS] Total: %.2f\n", sum_of_values);

    return 0;
}