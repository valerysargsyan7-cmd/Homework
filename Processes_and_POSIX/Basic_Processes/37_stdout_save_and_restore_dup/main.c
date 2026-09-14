#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

	printf("\n\nStdout Redirection & Restoration via dup() and dup2()\n\n");

	int saved_stdout = dup(STDOUT_FILENO);

	if(saved_stdout < 0){

		perror("[ERROR] Failed to save stdout via dup()");
		return 1;

	}

	const char *file_path = "temp.txt";
	int fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if(fd < 0){

		perror("[ERROR] Failed to open temp.txt");
		close(saved_stdout);
		return 1;

	}

	if(dup2(fd, STDOUT_FILENO) < 0){

		perror("[ERROR] dup2 failed to redirect stdout");
		close(fd);
		close(saved_stdout);
		return 1;

	}

	if(close(fd) < 0){

		perror("[ERROR] Failed to close original fd");
		close(saved_stdout);
		return 1;

	}

	printf("This text was written while stdout was redirected to temp.txt!\n");

	if(fflush(stdout) == EOF){

		perror("[ERROR] Failed to flush stdout buffer");
		close(saved_stdout);
		return 1;

	}

	if(dup2(saved_stdout, STDOUT_FILENO) < 0){

		perror("[ERROR] Failed to restore original stdout");
		close(saved_stdout);
		return 1;

	}

	if(close(saved_stdout) < 0){

		perror("[ERROR] Failed to close saved_stdout descriptor");
		return 1;

	}

	printf("[SUCCESS] Output stream successfully restored back to terminal screen!\n");

	int read_fd = open(file_path, O_RDONLY);
	if(read_fd >= 0){

		char buf[128];
		ssize_t n = read(read_fd, buf, sizeof(buf) - 1);
		if(n > 0){

			buf[n] = '\0';
			printf("\nContents verified inside temp.txt:\n  \"%s\"\n", buf);

		}
		close(read_fd);

	}

	return 0;

}
