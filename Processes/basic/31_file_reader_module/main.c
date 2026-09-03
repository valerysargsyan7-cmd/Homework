#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_reader.h"

int main()
{

	printf("\n\nFile Reader Module\n\n");

	const char *sample_file = "sample_data.txt";

	// Generate self-contained sample file
	FILE *fp = fopen(sample_file, "w");
	if(fp != NULL){

		fprintf(fp, "This is sample content read dynamically by the File Reader Module.\n"
		            "It calculates exact file length and allocates a properly sized buffer.\n");
		fclose(fp);

	}

	printf("Reading file '%s'...\n", sample_file);

	char *result = read_entire_file(sample_file);

	if(result != NULL){

		printf("\n====[ TEXT CONTENT ]====\n\n");
		printf("%s\n", result);
		printf("========================\n");
		free(result);

	}else{

		printf("[ERROR] Failed to read file content.\n");

	}

	return 0;

}
