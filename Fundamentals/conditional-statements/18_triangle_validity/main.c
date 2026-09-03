#include <stdio.h>

int main(void)
{
    int first_side = 0;
    int second_side = 0;
    int third_side = 0;
    int success_bit = 0;

    printf("\nTriangle checking\n");

    printf("\nEnter your first side: ");

    if(scanf("%d", &first_side) != 1){

        fprintf(stderr, "Error: Invalid first side.\n");
        return 1;

    }

    printf("Enter your second side: ");

    if(scanf("%d", &second_side) != 1){

        fprintf(stderr, "Error: Invalid second side.\n");
        return 1;

    }

    printf("Enter your third side: ");

    if(scanf("%d", &third_side) != 1){

        fprintf(stderr, "Error: Invalid third side.\n");
        return 1;

    }

    if(first_side <= 0 || second_side <= 0 || third_side <= 0){

        fprintf(stderr, "Error: Triangle sides must be positive.\n");
        return 1;

    }

    if((long long)first_side + second_side > third_side &&
       (long long)first_side + third_side > second_side &&
       (long long)second_side + third_side > first_side){

        success_bit = 1;
        printf("\nSUCCESS\n");

    }else{

        printf("\nUNSUCCESS\n");

    }

    if(success_bit == 1){

        if(first_side == second_side &&
           first_side == third_side){

            printf("\nEQUILATERAL\n");

        }else if(first_side == second_side ||
                 first_side == third_side ||
                 second_side == third_side){

            printf("\nISOSCELES\n");

        }else{

            printf("\nSCALENE\n");
        }
    }

    return 0;
}