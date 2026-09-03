#include <stdio.h>

struct Player{

	char name[50];
	int goals[5];
	int totalGoals;

};

int player_info_input(struct Player player[], int players_quantity);
void summing_goals(struct Player *player_ptr);
int best_index_return(struct Player player[], int player_quantity);

int main()
{
	printf("\n\nSoccer Team DataBase\n\n");

	int player_quantity = 3;

	struct Player player[3];


	printf("Inputing info\n");


	if(player_info_input(player, player_quantity) != 0){

		return 1;

	}


	for(int i = 0; i < player_quantity; i++){

		summing_goals(&player[i]);

	}


	int best_player = best_index_return(player, player_quantity);


	if(best_player == -1){

		fprintf(stderr, "[ERROR] Could not find best player.\n");
		return 1;

	}


	printf("\n\nBest player\n\n");

	printf("Name: %s\n", player[best_player].name);


	for(int i = 0; i < 5; i++){

		printf("Game %d goals: %d\n",
		       i + 1,
		       player[best_player].goals[i]);

	}


	printf("Total Goals: %d\n", player[best_player].totalGoals);


	return 0;
}



int player_info_input(struct Player player[], int players_quantity)
{
	for(int i = 0; i < players_quantity; i++){

		printf("\nEnter %dth player name: ", i + 1);

		if(scanf("%49s", player[i].name) != 1){

			fprintf(stderr, "[ERROR] Failed to read player name.\n");
			return 1;

		}


		for(int j = 0; j < 5; j++){

			printf("Enter goals for %dth player, game %d: ", i + 1, j + 1);

			if(scanf("%d", &player[i].goals[j]) != 1){

				fprintf(stderr, "[ERROR] Invalid goals value for player %d.\n", i + 1);
				return 1;

			}


			if(player[i].goals[j] < 0){

				fprintf(stderr, "[ERROR] Goals cannot be negative.\n");
				return 1;

			}
		}
	}

	return 0;
}


void summing_goals(struct Player *player_ptr)
{
	player_ptr->totalGoals = 0;


	for(int i = 0; i < 5; i++){

		player_ptr->totalGoals += player_ptr->goals[i];

	}
}


int best_index_return(struct Player player[], int player_quantity)
{
	if(player == NULL || player_quantity <= 0){

		return -1;

	}


	int max_index = 0;


	for(int i = 1; i < player_quantity; i++){

		if(player[i].totalGoals > player[max_index].totalGoals){

			max_index = i;

		}

	}


	return max_index;
}
