#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nParallel Matrix Row Multiplier (3 Processes)\n\n");

	const char *matrix_filename = "matrix.bin";
	const char *row1_filename = "row1.bin";
	const char *row2_filename = "row2.bin";
	const char *row3_filename = "row3.bin";

	int initial_matrix[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	FILE *matrix_fp = fopen(matrix_filename, "wb");
	if(matrix_fp == NULL){

		perror("[ERROR] Failed to create matrix.bin");
		return 1;

	}

	fwrite(initial_matrix, sizeof(int), 9, matrix_fp);
	fclose(matrix_fp);

	printf("[PARENT] -> Created 3x3 matrix in '%s'.\n", matrix_filename);

	pid_t child_4 = fork();
	if(child_4 < 0){

		perror("[ERROR] fork child 4 failed");
		return 1;

	}

	if(child_4 == 0){

		//CHILD 4 (Row 1)
		FILE *ch_4_fp = fopen(matrix_filename, "rb");
		if(ch_4_fp == NULL){

			perror("[ERROR] Child 4 fopen matrix");
			exit(1);

		}

		int *parsing_ch_4 = (int *)malloc(3 * sizeof(int));
		fread(parsing_ch_4, sizeof(int), 3, ch_4_fp);
		fclose(ch_4_fp);

		for(int j = 0; j < 3; j++){

			parsing_ch_4[j] *= 2;

		}

		FILE *row1_fp = fopen(row1_filename, "wb");
		if(row1_fp == NULL){

			perror("[ERROR] Child 4 fopen row1");
			free(parsing_ch_4);
			exit(1);

		}

		fwrite(parsing_ch_4, sizeof(int), 3, row1_fp);
		fclose(row1_fp);
		free(parsing_ch_4);

		printf("[CHILD 4] -> Row 1 multiplied by 2 and written to '%s'.\n", row1_filename);
		exit(0);

	}

	pid_t child_5 = fork();
	if(child_5 < 0){

		perror("[ERROR] fork child 5 failed");
		wait(NULL);
		return 1;

	}

	if(child_5 == 0){

		//CHILD 5 (Row 2)
		FILE *ch_5_fp = fopen(matrix_filename, "rb");
		if(ch_5_fp == NULL){

			perror("[ERROR] Child 5 fopen matrix");
			exit(1);

		}

		int *parsing_ch_5 = (int *)malloc(3 * sizeof(int));
		fseek(ch_5_fp, 3 * (long)sizeof(int), SEEK_SET);
		fread(parsing_ch_5, sizeof(int), 3, ch_5_fp);
		fclose(ch_5_fp);

		for(int j = 0; j < 3; j++){

			parsing_ch_5[j] *= 2;

		}

		FILE *row2_fp = fopen(row2_filename, "wb");
		if(row2_fp == NULL){

			perror("[ERROR] Child 5 fopen row2");
			free(parsing_ch_5);
			exit(1);

		}

		fwrite(parsing_ch_5, sizeof(int), 3, row2_fp);
		fclose(row2_fp);
		free(parsing_ch_5);

		printf("[CHILD 5] -> Row 2 multiplied by 2 and written to '%s'.\n", row2_filename);
		exit(0);

	}

	pid_t child_6 = fork();
	if(child_6 < 0){

		perror("[ERROR] fork child 6 failed");
		wait(NULL);
		wait(NULL);
		return 1;

	}

	if(child_6 == 0){

		//CHILD 6 (Row 3)
		FILE *ch_6_fp = fopen(matrix_filename, "rb");
		if(ch_6_fp == NULL){

			perror("[ERROR] Child 6 fopen matrix");
			exit(1);

		}

		int *parsing_ch_6 = (int *)malloc(3 * sizeof(int));
		fseek(ch_6_fp, 6 * (long)sizeof(int), SEEK_SET);
		fread(parsing_ch_6, sizeof(int), 3, ch_6_fp);
		fclose(ch_6_fp);

		for(int j = 0; j < 3; j++){

			parsing_ch_6[j] *= 2;

		}

		FILE *row3_fp = fopen(row3_filename, "wb");
		if(row3_fp == NULL){

			perror("[ERROR] Child 6 fopen row3");
			free(parsing_ch_6);
			exit(1);

		}

		fwrite(parsing_ch_6, sizeof(int), 3, row3_fp);
		fclose(row3_fp);
		free(parsing_ch_6);

		printf("[CHILD 6] -> Row 3 multiplied by 2 and written to '%s'.\n", row3_filename);
		exit(0);

	}

	//PARENT
	setpgid(child_4, child_4);
	setpgid(child_5, child_4);
	setpgid(child_6, child_4);

	wait(NULL);
	wait(NULL);
	wait(NULL);

	printf("\n[PARENT] -> All 3 worker children finished. Assembling dynamic 2D matrix...\n");

	int **parent_matrix = (int **)malloc(3 * sizeof(int *));
	for(int i = 0; i < 3; i++){

		parent_matrix[i] = (int *)malloc(3 * sizeof(int));

	}

	const char *row_files[3] = {row1_filename, row2_filename, row3_filename};

	for(int i = 0; i < 3; i++){

		FILE *rfp = fopen(row_files[i], "rb");
		if(rfp != NULL){

			fread(parent_matrix[i], sizeof(int), 3, rfp);
			fclose(rfp);

		}

	}

	printf("\n---- TRANSFORMED 3x3 MATRIX (Values * 2) ----\n\n");
	for(int i = 0; i < 3; i++){

		for(int j = 0; j < 3; j++){

			printf("%4d ", parent_matrix[i][j]);

		}
		printf("\n");

	}

	for(int i = 0; i < 3; i++){

		free(parent_matrix[i]);

	}
	free(parent_matrix);

	printf("\n[PARENT] -> Pipeline complete.\n");

	return 0;

}
