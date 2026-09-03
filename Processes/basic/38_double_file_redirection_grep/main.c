#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nDual File Redirection Pipeline (grep < input.log > errors.txt)\n\n");

	const char *file_path_input = "input.log";
	const char *file_path_errors = "errors.txt";

	int prep_fd = open(file_path_input, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if(prep_fd < 0){

		perror("[ERROR] Failed to create input.log");
		return 1;

	}

	const char log_content[] =
		"INFO: Service started normally\n"
		"WARNING: High memory usage detected\n"
		"error: Database connection timeout occurred\n"
		"DEBUG: Heartbeat ping successful\n"
		"error: Failed to write packet to socket\n";

	if(write(prep_fd, log_content, sizeof(log_content) - 1) < 0){

		perror("[ERROR] Failed to write log content");
		close(prep_fd);
		return 1;

	}

	if(close(prep_fd) < 0){

		perror("[ERROR] Failed to close prep_fd");
		return 1;

	}

	printf("[PARENT] -> Prepared 'input.log' with sample log entries.\n");
	printf("[PARENT] -> Spawning child process to execute: grep error < input.log > errors.txt...\n");

	pid_t pid = fork();

	if(pid < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(pid == 0){

		//CHILD PROCESS
		int fd_input = open(file_path_input, O_RDONLY);

		if(fd_input < 0){

			perror("[ERROR] Failed to open input.log for reading");
			exit(1);

		}

		if(dup2(fd_input, STDIN_FILENO) < 0){

			perror("[ERROR] dup2 failed on stdin redirection");
			close(fd_input);
			exit(1);

		}

		if(close(fd_input) < 0){

			perror("[ERROR] Failed to close fd_input");
			exit(1);

		}

		int fd_errors = open(file_path_errors, O_WRONLY | O_CREAT | O_TRUNC, 0644);

		if(fd_errors < 0){

			perror("[ERROR] Failed to open errors.txt for writing");
			exit(1);

		}

		if(dup2(fd_errors, STDOUT_FILENO) < 0){

			perror("[ERROR] dup2 failed on stdout redirection");
			close(fd_errors);
			exit(1);

		}

		if(close(fd_errors) < 0){

			perror("[ERROR] Failed to close fd_errors");
			exit(1);

		}

		execlp("grep", "grep", "error", NULL);

		perror("[ERROR] execlp grep failed");
		exit(1);

	}else{

		//PARENT PROCESS
		int status;
		if(waitpid(pid, &status, 0) < 0){

			perror("[ERROR] waitpid failed");
			return 1;

		}

		printf("\n[PARENT] -> Grep filtering finished. Filtered results in 'errors.txt':\n");
		printf("============================================================\n");

		int read_fd = open(file_path_errors, O_RDONLY);

		if(read_fd >= 0){

			char buf[512];
			ssize_t n = read(read_fd, buf, sizeof(buf) - 1);

			if(n > 0){

				buf[n] = '\0';
				printf("%s", buf);

			}

			close(read_fd);

		}

		printf("============================================================\n");

	}

	return 0;

}
