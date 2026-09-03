#include <stdio.h>

struct Point
{
    int x;
    int y;
};

enum Direction
{
    STOP = 0,
    NORTH = 1,
    SOUTH = 2,
    EAST = 3,
    WEST = 4
};

int main(void)
{
    struct Point point = {0, 0};
    int command = 0;

    printf("\n=== Moving by Coordinates ===\n\n");

    while(1){

        printf(
            "\n"
            "  1 - North\n"
            "  2 - South\n"
            "  3 - East\n"
            "  4 - West\n"
            "  0 - Exit\n"
            "Enter command: "
        );

        if(scanf("%d", &command) != 1){

            fprintf(stderr, "[ERROR] Invalid command.\n");
            return 1;

        }

        switch(command){

            case NORTH:
                point.y++;
                break;

            case SOUTH:
                point.y--;
                break;

            case EAST:
                point.x++;
                break;

            case WEST:
                point.x--;
                break;

            case STOP:
                printf("\n[INFO] Goodbye!\n");
                return 0;

            default:
                printf("[ERROR] Unknown command.\n");
                continue;
        }

        printf(
            "\n[SUCCESS] Current position: (%d, %d)\n",
            point.x,
            point.y
        );
    }
}