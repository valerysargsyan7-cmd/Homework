#include <stdio.h>

int main(void)
{
    int person_age = 0;
    float person_height = 0.0f;

    printf("\nFace control\n");

    printf("\nEnter your age: ");

    if(scanf("%d", &person_age) != 1){

        fprintf(stderr, "Error: Invalid age.\n");
        return 1;

    }

    printf("Enter your height: ");

    if(scanf("%f", &person_height) != 1){

        fprintf(stderr, "Error: Invalid height.\n");
        return 1;

    }

    if(person_age < 0 || person_height < 0.0f){

        fprintf(stderr, "Error: Age and height cannot be negative.\n");
        return 1;

    }

    printf("\n%d\n", person_age > 18 && person_height > 1.60f);

    return 0;
}