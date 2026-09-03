#include <stdio.h>

struct StudentInfo{

    char student_name[20];
    int student_age;
    float student_grade;

};

int main()
{
    printf("\n\nStudents DataBase\n\n");

    struct StudentInfo student[3];

    for(int i = 0; i < 3; i++){

        printf("Enter name for student %d: ", i + 1);

        if(scanf("%19s", student[i].student_name) != 1){

            fprintf(stderr, "[ERROR] Invalid name input.\n");
            return 1;
        }

        printf("Enter age for student %d: ", i + 1);

        if(scanf("%d", &student[i].student_age) != 1){

            fprintf(stderr, "[ERROR] Invalid age input.\n");
            return 1;

        }

        printf("Enter grade for student %d: ", i + 1);

        if(scanf("%f", &student[i].student_grade) != 1){

            fprintf(stderr, "[ERROR] Invalid grade input.\n");
            return 1;

        }
        
    }

    int current_student = 0;

    for(int i = 1; i < 3; i++){

        if(student[i].student_grade > student[current_student].student_grade){

            current_student = i;

        }

    }

    printf("\nStudent with highest grade:\n");
    printf("Name: %s\n", student[current_student].student_name);
    printf("Age: %d\n", student[current_student].student_age);
    printf("Grade: %.2f\n", student[current_student].student_grade);

    return 0;
}