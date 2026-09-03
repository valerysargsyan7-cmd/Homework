#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int are_files_equal(const char *first_file, const char *second_file);

int main()
{

	printf("\n\nByte-by-Byte File Equality Comparator\n\n");

	const char *file1 = "test1.txt";
	const char *file2 = "test2.txt";
	const char *file3 = "test3.txt";

	FILE *fp1 = fopen(file1, "w");
	FILE *fp2 = fopen(file2, "w");
	FILE *fp3 = fopen(file3, "w");

	if(fp1 && fp2 && fp3){

		fprintf(fp1, "Identical content for verification.\n");
		fprintf(fp2, "Identical content for verification.\n");
		fprintf(fp3, "Different content entirely.\n");
		fclose(fp1);
		fclose(fp2);
		fclose(fp3);

	}

	printf("Comparing '%s' and '%s':\n", file1, file2);
	if(are_files_equal(file1, file2)){

		printf("Result: Files are IDENTICAL (Equal)\n");

	}else{

		printf("Result: Files are DIFFERENT\n");

	}

	printf("\nComparing '%s' and '%s':\n", file1, file3);
	if(are_files_equal(file1, file3)){

		printf("Result: Files are IDENTICAL (Equal)\n");

	}else{

		printf("Result: Files are DIFFERENT\n");

	}

	return 0;

}

int are_files_equal(const char *first_file, const char *second_file)
{

	FILE *first_file_fp = fopen(first_file, "r");

	if(first_file_fp == NULL){

		perror("[ERROR] File opening error for first file");
		return 0;

	}

	FILE *second_file_fp = fopen(second_file, "r");

	if(second_file_fp == NULL){

		perror("[ERROR] File opening error for second file");
		fclose(first_file_fp);
		return 0;

	}

	int first_symb;
	int second_symb;

	while(((first_symb = fgetc(first_file_fp)) != EOF) &&
	      ((second_symb = fgetc(second_file_fp)) != EOF)){

		if(first_symb != second_symb){

			fclose(first_file_fp);
			fclose(second_file_fp);
			return 0;

		}

	}

	int is_equal = (first_symb == EOF && second_symb == EOF);

	fclose(first_file_fp);
	fclose(second_file_fp);

	return is_equal;

}
