#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

	printf("\n\nStandard Input Redirection via dup2()\n\n");

	const char *file_path = "data.txt";

	int prep_fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if(prep_fd < 0){

		perror("[ERROR] Failed to prepare data.txt");
		return 1;

	}

	const char sample_data[] = "Line read directly from redirected stdin via dup2!\n";

	if(write(prep_fd, sample_data, sizeof(sample_data) - 1) < 0){

		perror("[ERROR] Failed to write initial sample data");
		close(prep_fd);
		return 1;

	}

	if(close(prep_fd) < 0){

		perror("[ERROR] Failed to close prep_fd");
		return 1;

	}

	int fd = open(file_path, O_RDONLY);

	if(fd < 0){

		perror("[ERROR] file open error");
		return 1;

	}

	if(dup2(fd, STDIN_FILENO) < 0){

		perror("[ERROR] dup2 failed to redirect stdin");
		close(fd);
		return 1;

	}

	if(close(fd) < 0){

		perror("[ERROR] Failed to close original fd");
		return 1;

	}

	char buffer[1024];

	if(fgets(buffer, sizeof(buffer), stdin) == NULL){

		fprintf(stderr, "[ERROR] fgets failed to read from redirected stdin.\n");
		return 1;

	}

	printf("Output read from redirected stdin:\n");
	printf("%s", buffer);

	return 0;

}
