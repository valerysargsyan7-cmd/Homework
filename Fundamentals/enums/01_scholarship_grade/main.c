#include <stdio.h>

enum Grade
{
    POOR = 2,
    SATISFACTORY = 3,
    GOOD = 4,
    EXCELLENT = 5
};

int main(void)
{
    enum Grade score;
    int grade_input = 0;

    printf("\n=== Scholarship by Grade ===\n\n");

    printf(
        "Enter your grade "
        "(POOR-2, SATISFACTORY-3, GOOD-4, EXCELLENT-5): "
    );

    if(scanf("%d", &grade_input) != 1){

        fprintf(stderr, "[ERROR] Invalid grade.\n");
        return 1;

    }

    if(grade_input < POOR || grade_input > EXCELLENT){

        fprintf(stderr, "[ERROR] Grade must be between 2 and 5.\n");
        return 1;

    }

    score = (enum Grade)grade_input;

    switch(score){

        case GOOD:
        case EXCELLENT:
            printf("\n[SUCCESS] Scholarship awarded.\n");
            break;

        case POOR:
        case SATISFACTORY:
            printf("\n[INFO] No scholarship.\n");
            break;

        default:
            fprintf(stderr, "[ERROR] Invalid grade.\n");
            return 1;
    }

    return 0;
}