#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void read_lines(const char *filename);
long get_size(const char *filename);

int main()
{

	printf("\n\nFile Lines Reader & Size Calculation\n\n");

	const char *filename = "Reading_file.txt";

	int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);

	if(fd < 0){

		perror("[ERROR] Failed to create file");
		return 1;

	}

	const char *first_line = "Hello my name is John Smith\n";
	const char *second_line = "Hello my name is Rick Sanchez\n";
	const char *third_line = "Hello my name is Morty Smith\n";

	write(fd, first_line, strlen(first_line));
	write(fd, second_line, strlen(second_line));
	write(fd, third_line, strlen(third_line));

	close(fd);

	printf("--- Reading Line by Line ---\n");
	read_lines(filename);

	printf("\n--- File Size Calculation ---\n");
	long size = get_size(filename);
	printf("\n[The total size of '%s' is: %ld bytes]\n", filename, size);

	return 0;

}

void read_lines(const char *filename)
{

	FILE *fp = fopen(filename, "r");

	if(fp == NULL){

		perror("[ERROR] File opening error in read_lines");
		return;

	}

	char read_text[256];
	int line_quantity = 1;

	while(fgets(read_text, sizeof(read_text), fp) != NULL){

		printf("%d: %s", line_quantity, read_text);
		line_quantity++;

	}

	fclose(fp);

}

long get_size(const char *filename)
{

	FILE *fp_get_size = fopen(filename, "r");

	if(fp_get_size == NULL){

		perror("[ERROR] File opening error in get_size");
		return -1;

	}

	if(fseek(fp_get_size, 0, SEEK_END) != 0){

		perror("[ERROR] fseek failed");
		fclose(fp_get_size);
		return -1;

	}

	long bytes = ftell(fp_get_size);
	fclose(fp_get_size);

	return bytes;

}
