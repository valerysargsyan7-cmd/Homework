#include <stdio.h>

int main(void)
{
    float gpa = 0.0f;
    int age = 0;

    printf("\nScholarship\n");

    printf("\nEnter your GPA: ");

    if(scanf("%f", &gpa) != 1){

        fprintf(stderr, "Error: Invalid GPA.\n");
        return 1;

    }

    printf("Enter your age: ");

    if(scanf("%d", &age) != 1){

        fprintf(stderr, "Error: Invalid age.\n");
        return 1;

    }

    if(gpa < 0.0f || gpa > 100.0f){

        fprintf(stderr, "Error: GPA must be between 0 and 100.\n");
        return 1;

    }

    if(age < 0){

        fprintf(stderr, "Error: Age cannot be negative.\n");
        return 1;

    }

    if(gpa > 90.0f && age < 20){

        printf("\nYou get a scholarship\n");

    }else{

        printf("\nYou don't get a scholarship\n");
    }

    return 0;
}