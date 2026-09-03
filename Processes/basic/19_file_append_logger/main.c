#include <stdio.h>
#include <stdlib.h>

void append_log(const char *filename, const char *msg);

int main()
{

	printf("\n\nFile Append Logger\n\n");

	const char *logfilename = "File.log";
	const char *mode = "a";

	append_log(logfilename, mode);

	printf("Log entry recorded successfully in %s.\n", logfilename);

	FILE *fp = fopen(logfilename, "r");
	if(fp != NULL){

		char line[128];
		printf("\n--- File Content (%s) ---\n", logfilename);
		while(fgets(line, sizeof(line), fp)){

			printf("%s", line);

		}
		fclose(fp);

	}

	return 0;

}

void append_log(const char *filename, const char *msg)
{

	FILE *fp = fopen(filename, msg);

	if(fp == NULL){

		perror("[ERROR] Failed to open log file");
		return;

	}

	fprintf(fp, "%s", "[LOG]: User entered\n");
	fflush(fp);
	fclose(fp);

}
