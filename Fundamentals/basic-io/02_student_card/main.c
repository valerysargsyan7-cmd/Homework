#include <stdio.h>

int main(void)
{
    int student_age = 0;
    float student_average_mark = 0.0f;

    printf("\nStudent card\n");

    printf("\nEnter your age: ");

    if(scanf("%d", &student_age) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(student_age < 0){

        fprintf(stderr, "Error: Age cannot be negative.\n");
        return 1;

    }

    printf("Enter your average mark: ");

    if(scanf("%f", &student_average_mark) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid number.\n");
        return 1;

    }

    if(student_average_mark < 0.0f){

        fprintf(stderr, "Error: Score cannot be negative.\n");
        return 1;

    }

    printf("\nAge: %d, Score: %.2f\n", student_age, student_average_mark);

    return 0;
}