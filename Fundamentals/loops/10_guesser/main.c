#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{

	printf("\n\nShazam\n\n");

	srand((unsigned int)time(NULL));


	int rand_num = rand() % 100 + 1;
	int user_num = 0;


	do{

		printf("Enter number for guess from 1 to 100: ");

		if(scanf("%d", &user_num) != 1){

			printf("\n[ERROR] Invalid input!\n");
			return 1;

		}


		if(user_num < 1 || user_num > 100){

			printf("\n[ERROR] Number must be between 1 and 100!\n");
			continue;

		}


		if(user_num == rand_num){

			printf("\nGot it!\n");

		}else if(user_num > rand_num){

			printf("\nLower\n");

		}else{

			printf("\nHigher\n");

		}

	}while(user_num != rand_num);


	return 0;

}