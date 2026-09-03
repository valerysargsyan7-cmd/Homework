#include <stdio.h>

int main(void)
{
    int english = 0;
    int math = 0;
    int physics = 0;
    int history = 0;
    float average = 0.0f;

    printf("\nAverage rating\n");

    printf("\nEnter your English mark: ");
    if(scanf("%d", &english) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("Enter your Math mark: ");
    if(scanf("%d", &math) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("Enter your Physics mark: ");

    if(scanf("%d", &physics) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    printf("Enter your History mark: ");
    
    if(scanf("%d", &history) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    average = (english + math + physics + history) / 4.0f;

    printf("\nYour average score is: %.2f\n", average);

    return 0;
}