#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	int fds[2];

	if(pipe(fds) == -1){

		perror("[ERROR] pipe creation failed");
		return 1;

	}

	pid_t pid_1 = fork();

	if(pid_1 < 0){

		perror("[ERROR] fork child 1 failed");
		close(fds[0]);
		close(fds[1]);
		return 1;

	}

	if(pid_1 == 0){

		//CHILD 1: 'ls'
		if(close(fds[0]) < 0){

			perror("[ERROR] Child 1 failed to close read end");

		}

		if(dup2(fds[1], STDOUT_FILENO) < 0){

			perror("[ERROR] Child 1 dup2 failed to redirect stdout");
			close(fds[1]);
			exit(1);

		}

		if(close(fds[1]) < 0){

			perror("[ERROR] Child 1 failed to close write end");

		}

		execlp("ls", "ls", NULL);

		perror("[ERROR] Child 1 execlp 'ls' failed");
		exit(1);

	}

	pid_t pid_2 = fork();

	if(pid_2 < 0){

		perror("[ERROR] fork child 2 failed");
		close(fds[0]);
		close(fds[1]);
		waitpid(pid_1, NULL, 0);
		return 1;

	}

	if(pid_2 == 0){

		//CHILD 2: 'wc -l'
		if(close(fds[1]) < 0){

			perror("[ERROR] Child 2 failed to close write end");

		}

		if(dup2(fds[0], STDIN_FILENO) < 0){

			perror("[ERROR] Child 2 dup2 failed to redirect stdin");
			close(fds[0]);
			exit(1);

		}

		if(close(fds[0]) < 0){

			perror("[ERROR] Child 2 failed to close read end");

		}

		execlp("wc", "wc", "-l", NULL);

		perror("[ERROR] Child 2 execlp 'wc' failed");
		exit(1);

	}

	if(close(fds[0]) < 0){

		perror("[ERROR] Parent failed to close read end");

	}

	if(close(fds[1]) < 0){

		perror("[ERROR] Parent failed to close write end");

	}

	int status1, status2;
	waitpid(pid_1, &status1, 0);
	waitpid(pid_2, &status2, 0);

	return 0;

}
