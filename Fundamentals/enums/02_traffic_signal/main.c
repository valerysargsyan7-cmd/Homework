#include <stdio.h>

typedef enum
{
    RED,
    YELLOW,
    GREEN

} Signal;

int main(void)
{
    Signal signal;
    int signal_input = 0;

    printf("\n=== Traffic Signal ===\n\n");

    printf(
        "Enter signal "
        "(RED-0, YELLOW-1, GREEN-2): "
    );

    if(scanf("%d", &signal_input) != 1){

        fprintf(stderr, "[ERROR] Invalid signal.\n");
        return 1;

    }

    if(signal_input < RED || signal_input > GREEN){

        fprintf(stderr, "[ERROR] Signal must be 0, 1, or 2.\n");
        return 1;

    }

    signal = (Signal)signal_input;

    switch(signal){

        case RED:
            printf("\n[INFO] Wait...\n");
            break;

        case YELLOW:
            printf("\n[INFO] Get ready.\n");
            break;

        case GREEN:
            printf("\n[SUCCESS] GO!\n");
            break;

        default:
            fprintf(stderr, "[ERROR] Invalid signal.\n");
            return 1;
    }

    return 0;
}