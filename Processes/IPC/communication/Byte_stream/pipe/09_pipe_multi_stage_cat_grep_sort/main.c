#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{

	const char *sample_file = "data.txt";

	int prep_fd = open(sample_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if(prep_fd < 0){

		perror("[ERROR] Failed to create data.txt");
		return 1;

	}

	const char sample_content[] =
		"Banana\n"
		"Apple\n"
		"Orange\n"
		"Avocado\n"
		"Kiwi\n"
		"Apricot\n"
		"Cherry\n";

	if(write(prep_fd, sample_content, sizeof(sample_content) - 1) < 0){

		perror("[ERROR] Failed to write sample content");
		close(prep_fd);
		return 1;

	}

	if(close(prep_fd) < 0){

		perror("[ERROR] Failed to close prep_fd");
		return 1;

	}

	int fds_1[2];
	int fds_2[2];

	if(pipe(fds_1) == -1){

		perror("[ERROR] Failed to create pipe 1");
		return 1;

	}

	if(pipe(fds_2) == -1){

		perror("[ERROR] Failed to create pipe 2");
		close(fds_1[0]);
		close(fds_1[1]);
		return 1;

	}

	pid_t pid_1 = fork();

	if(pid_1 < 0){

		perror("[ERROR] fork child 1 failed");
		close(fds_1[0]); close(fds_1[1]);
		close(fds_2[0]); close(fds_2[1]);
		return 1;

	}

	if(pid_1 == 0){

		//CHILD 1: 'cat data.txt'
		close(fds_1[0]);
		close(fds_2[0]);
		close(fds_2[1]);

		if(dup2(fds_1[1], STDOUT_FILENO) < 0){

			perror("[ERROR] Child 1 dup2 failed");
			close(fds_1[1]);
			exit(1);

		}

		close(fds_1[1]);

		execlp("cat", "cat", sample_file, NULL);

		perror("[ERROR] Child 1 execlp cat failed");
		exit(1);

	}

	pid_t pid_2 = fork();

	if(pid_2 < 0){

		perror("[ERROR] fork child 2 failed");
		close(fds_1[0]); close(fds_1[1]);
		close(fds_2[0]); close(fds_2[1]);
		waitpid(pid_1, NULL, 0);
		return 1;

	}

	if(pid_2 == 0){

		//CHILD 2: 'grep A'
		close(fds_1[1]);
		close(fds_2[0]);

		if(dup2(fds_1[0], STDIN_FILENO) < 0){

			perror("[ERROR] Child 2 dup2 stdin failed");
			close(fds_1[0]);
			close(fds_2[1]);
			exit(1);

		}

		if(dup2(fds_2[1], STDOUT_FILENO) < 0){

			perror("[ERROR] Child 2 dup2 stdout failed");
			close(fds_1[0]);
			close(fds_2[1]);
			exit(1);

		}

		close(fds_1[0]);
		close(fds_2[1]);

		execlp("grep", "grep", "A", NULL);

		perror("[ERROR] Child 2 execlp grep failed");
		exit(1);

	}

	pid_t pid_3 = fork();

	if(pid_3 < 0){

		perror("[ERROR] fork child 3 failed");
		close(fds_1[0]); close(fds_1[1]);
		close(fds_2[0]); close(fds_2[1]);
		waitpid(pid_1, NULL, 0);
		waitpid(pid_2, NULL, 0);
		return 1;

	}

	if(pid_3 == 0){

		//CHILD 3: 'sort'
		close(fds_1[0]);
		close(fds_1[1]);
		close(fds_2[1]);

		if(dup2(fds_2[0], STDIN_FILENO) < 0){

			perror("[ERROR] Child 3 dup2 stdin failed");
			close(fds_2[0]);
			exit(1);

		}

		close(fds_2[0]);

		execlp("sort", "sort", NULL);

		perror("[ERROR] Child 3 execlp sort failed");
		exit(1);

	}

	close(fds_1[0]);
	close(fds_1[1]);
	close(fds_2[0]);
	close(fds_2[1]);

	int status1, status2, status3;
	waitpid(pid_1, &status1, 0);
	waitpid(pid_2, &status2, 0);
	waitpid(pid_3, &status3, 0);

	return 0;

}
