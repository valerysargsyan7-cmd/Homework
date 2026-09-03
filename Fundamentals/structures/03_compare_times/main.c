#include <stdio.h>

struct Time
{
    int hour;
    int minute;
};

int main(void)
{
    struct Time first_time;
    struct Time second_time;

    printf("\n=== Compare Two Times ===\n\n");

    printf("Enter hours of first time: ");

    if(scanf("%d", &first_time.hour) != 1){

        fprintf(stderr, "[ERROR] Invalid hour.\n");
        return 1;

    }

    printf("Enter minutes of first time: ");

    if(scanf("%d", &first_time.minute) != 1){

        fprintf(stderr, "[ERROR] Invalid minutes.\n");
        return 1;

    }

    printf("\nEnter hours of second time: ");

    if(scanf("%d", &second_time.hour) != 1){

        fprintf(stderr, "[ERROR] Invalid hour.\n");
        return 1;

    }

    printf("Enter minutes of second time: ");

    if(scanf("%d", &second_time.minute) != 1){

        fprintf(stderr, "[ERROR] Invalid minutes.\n");
        return 1;

    }

    if(first_time.hour < 0 || first_time.hour > 23 ||
       second_time.hour < 0 || second_time.hour > 23 ||
       first_time.minute < 0 || first_time.minute > 59 ||
       second_time.minute < 0 || second_time.minute > 59){

        fprintf(stderr, "[ERROR] Invalid time. Use HH:MM format.\n");
        return 1;

    }

    if(first_time.hour > second_time.hour ||
       (first_time.hour == second_time.hour &&
        first_time.minute > second_time.minute)){

        printf(
            "\n[INFO] %02d:%02d is later than %02d:%02d.\n",
            first_time.hour,
            first_time.minute,
            second_time.hour,
            second_time.minute
        );

    }else if(first_time.hour == second_time.hour &&
             first_time.minute == second_time.minute){

        printf(
            "\n[INFO] %02d:%02d equals %02d:%02d.\n",
            first_time.hour,
            first_time.minute,
            second_time.hour,
            second_time.minute
        );

    }else{

        printf(
            "\n[INFO] %02d:%02d is later than %02d:%02d.\n",
            second_time.hour,
            second_time.minute,
            first_time.hour,
            first_time.minute
        );
    }

    return 0;
}