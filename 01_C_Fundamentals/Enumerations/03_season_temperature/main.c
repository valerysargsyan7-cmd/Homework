#include <stdio.h>

enum Season
{
    SPRING,
    SUMMER,
    AUTUMN,
    WINTER
};

int main(void)
{
    enum Season user_choice;
    int season_input = 0;

    printf("\n=== Season Temperature ===\n\n");

    printf(
        "Choose a season:\n"
        "  0 - Spring\n"
        "  1 - Summer\n"
        "  2 - Autumn\n"
        "  3 - Winter\n\n"
        "Enter your choice: "
    );

    if(scanf("%d", &season_input) != 1){

        fprintf(stderr, "[ERROR] Invalid input.\n");
        return 1;

    }

    if(season_input < SPRING || season_input > WINTER){

        fprintf(stderr, "[ERROR] Invalid season.\n");
        return 1;

    }

    user_choice = (enum Season)season_input;

    switch(user_choice){

        case SPRING:
            printf("\n[INFO] Temperature range: +11 to +25 C\n");
            break;

        case SUMMER:
            printf("\n[INFO] Temperature range: +16 to +40 C\n");
            break;

        case AUTUMN:
            printf("\n[INFO] Temperature range: +10 to +25 C\n");
            break;

        case WINTER:
            printf("\n[INFO] Temperature range: -5 to +6 C\n");
            break;

        default:
            fprintf(stderr, "[ERROR] Invalid season.\n");
            return 1;
    }

    return 0;
}