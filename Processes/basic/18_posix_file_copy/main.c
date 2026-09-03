#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void copy_file(const char *src, const char *dest);

int main()
{

	printf("\n\nPOSIX File Copy\n\n");

	const char *src = "Source_file.txt";
	const char *dest = "Destination_file.txt";

	copy_file(src, dest);

	return 0;

}

void copy_file(const char *src, const char *dest)
{

	int src_init_fd = open(src, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if(src_init_fd < 0){

		perror("[ERROR] Failed to create source file");
		return;

	}

	const char *sample = "Hello my name is John Smith\n";
	write(src_init_fd, sample, strlen(sample));
	close(src_init_fd);

	int src_fd = open(src, O_RDONLY);

	if(src_fd < 0){

		perror("[ERROR] Failed to open source file for reading");
		return;

	}

	int dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if(dest_fd < 0){

		perror("[ERROR] Failed to open destination file");
		close(src_fd);
		return;

	}

	char buffer[128];
	ssize_t bytes_read;

	while((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0){

		if(write(dest_fd, buffer, bytes_read) != bytes_read){

			perror("[ERROR] Write failure during copy");
			break;

		}

	}

	close(src_fd);
	close(dest_fd);

	printf("\nCopy status: DONE\n");

	FILE *fp = fopen(dest, "r");
	if(fp != NULL){

		char line[128];
		printf("Copied Content: ");
		while(fgets(line, sizeof(line), fp)){

			printf("%s", line);

		}
		fclose(fp);

	}

}
