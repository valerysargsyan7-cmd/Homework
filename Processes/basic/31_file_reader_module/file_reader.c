#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_reader.h"

char *read_entire_file(const char *path)
{

	FILE *reader_fp = fopen(path, "rb");

	if(reader_fp == NULL){

		perror("[ERROR] fopen error in read_entire_file");
		return NULL;

	}

	if(fseek(reader_fp, 0, SEEK_END) != 0){

		perror("[ERROR] fseek error");
		fclose(reader_fp);
		return NULL;

	}

	long file_len = ftell(reader_fp);

	if(file_len < 0){

		perror("[ERROR] ftell error");
		fclose(reader_fp);
		return NULL;

	}

	rewind(reader_fp);

	char *buffer = (char *)malloc((size_t)file_len + 1);

	if(buffer == NULL){

		perror("[ERROR] malloc error in read_entire_file");
		fclose(reader_fp);
		return NULL;

	}

	size_t read_bytes = fread(buffer, 1, (size_t)file_len, reader_fp);
	buffer[read_bytes] = '\0';

	fclose(reader_fp);
	return buffer;

}
