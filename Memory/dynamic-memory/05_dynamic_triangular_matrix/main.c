#include <stdio.h>
#include <stdlib.h>

int main()
{

	printf("\n\nDynamic 2D Lower-Triangular Matrix\n\n");

	int matrix_row = 0;

	printf("Enter matrix row count (dimension N): ");
	if(scanf("%d", &matrix_row) != 1 || matrix_row <= 0){

		fprintf(stderr, "[ERROR] Invalid matrix dimension.\n");
		return 1;

	}

	int **matrix = (int **)malloc((size_t)matrix_row * sizeof(int *));

	if(matrix == NULL){

		perror("[ERROR] Failed to allocate row pointer array");
		return 1;

	}

	for(int i = 0; i < matrix_row; i++){

		matrix[i] = (int *)malloc((size_t)matrix_row * sizeof(int));

		if(matrix[i] == NULL){

			perror("[ERROR] Failed to allocate matrix row");
			for(int k = 0; k < i; k++){

				free(matrix[k]);

			}
			free(matrix);
			return 1;

		}

	}

	for(int i = 0; i < matrix_row; i++){

		for(int j = 0; j <= i; j++){

			matrix[i][j] = i + j;

		}

	}

	printf("\n---- LOWER TRIANGULAR MATRIX ----\n\n");

	for(int i = 0; i < matrix_row; i++){

		for(int j = 0; j <= i; j++){

			printf("%3d ", matrix[i][j]);

		}

		printf("\n");

	}

	for(int i = 0; i < matrix_row; i++){

		free(matrix[i]);

	}

	free(matrix);

	printf("\nMatrix memory deallocated cleanly.\n");

	return 0;

}
