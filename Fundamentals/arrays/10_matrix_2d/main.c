#include <stdio.h>

int main()
{

	printf("\n\nMatrix\n\n");

	int matrix[3][3];


	for(int i = 0; i < 3; i++){

		for(int j = 0; j < 3; j++){

			printf("Enter matrix[%d][%d]: ", i, j);

			if(scanf("%d", &matrix[i][j]) != 1){

				printf("\n[ERROR] Invalid input!\n");
				return 1;

			}

		}

	}


	printf("\nMatrix:\n\n");


	for(int i = 0; i < 3; i++){

		for(int j = 0; j < 3; j++){

			printf("%d ", matrix[i][j]);

		}

		printf("\n");

	}


	return 0;

}