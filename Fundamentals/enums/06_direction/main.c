#include <stdio.h>


typedef enum {

	NORTH,
	EAST,
	SOUTH,
	WEST

} Direction;


int main()
{


	printf("\n\nDirection\n\n");

	Direction moving_direction;
	int direction_choice = 0;

	printf("\nEnter direction for moving 0-NORTH, 1-EAST, 2-SOUTH, 3-WEST: ");

	if(scanf("%d", &direction_choice) != 1){

		printf("[ERROR] Invalid direction input!\n");
		return 1;

	}


	if(direction_choice < NORTH || direction_choice > WEST){

		printf("\n[ERROR] Unknown direction!\n");
		return 1;

	}


	moving_direction = (Direction)direction_choice;


	switch(moving_direction){

		case NORTH:
			printf("\nMoving north\n");
			break;

		case EAST:
			printf("\nMoving east\n");
			break;

		case SOUTH:
			printf("\nMoving south\n");
			break;

		case WEST:
			printf("\nMoving west\n");
			break;

		default:
			printf("\n[ERROR] Unknown direction!\n");
			return 1;

	}


	return 0;
}