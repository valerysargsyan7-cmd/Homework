#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

	const char *file_path = "app.log";

	int fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if(fd < 0){

		perror("[ERROR] Failed to open/create app.log");
		return 1;

	}

	if(dup2(fd, STDOUT_FILENO) < 0){

		perror("[ERROR] dup2 failed for STDOUT_FILENO");
		close(fd);
		return 1;

	}

	if(dup2(fd, STDERR_FILENO) < 0){

		perror("[ERROR] dup2 failed for STDERR_FILENO");
		close(fd);
		return 1;

	}

	if(close(fd) < 0){

		perror("[ERROR] Failed to close original fd");
		return 1;

	}

	printf("[INFO] This text is normal standard output (stdout).\n");
	fprintf(stderr, "[ERROR] This text is an error log entry (stderr).\n");

	fflush(stdout);
	fflush(stderr);

	return 0;

}
