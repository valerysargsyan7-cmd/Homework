#include <stdio.h>

int main(void)
{
    int goal_num = 0;

    printf("\nGoal calculating\n");

    printf("\nEnter your hit place: ");

    if(scanf("%d", &goal_num) != 1){

        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\n");
        return 1;

    }

    if(goal_num >= 1 && goal_num <= 10){

        printf("\nGOAL\n");

    }else{

        printf("\nOUT\n");
    }

    return 0;
}