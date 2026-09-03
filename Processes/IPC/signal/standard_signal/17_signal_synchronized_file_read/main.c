#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

volatile sig_atomic_t file_ready_flag = 0;

void sigusr1_handler(int sig_num)
{
	(void)sig_num;
	file_ready_flag = 1;
}

int main()
{

	printf("\n\nSignal-Synchronized File Read (SIGUSR1)\n\n");

	const char *parent_filename = "Parent.txt";

	pid_t child_1 = fork();

	if(child_1 < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(child_1 == 0){

		//CHILD
		if(signal(SIGUSR1, sigusr1_handler) == SIG_ERR){

			perror("[ERROR] signal registration failed");
			exit(1);

		}

		printf("[CHILD] -> Waiting for parent to finish writing (SIGUSR1)...\n");

		while(!file_ready_flag){

			pause();

		}

		printf("[CHILD] -> Signal received! Opening '%s'...\n\n", parent_filename);

		int child_fd = open(parent_filename, O_RDONLY);

		if(child_fd < 0){

			perror("[ERROR] Failed to open file in child");
			exit(1);

		}

		char child_buf[256];
		ssize_t bytes;

		while((bytes = read(child_fd, child_buf, sizeof(child_buf) - 1)) > 0){

			child_buf[bytes] = '\0';
			printf("%s", child_buf);

		}

		close(child_fd);
		printf("\n[CHILD] -> Process status: DONE\n");
		exit(0);

	}else{

		//PARENT
		printf("[PARENT] -> Writing lines to '%s'...\n", parent_filename);

		FILE *parent_fp = fopen(parent_filename, "w+");

		if(parent_fp == NULL){

			perror("[ERROR] File opening error in parent");
			kill(child_1, SIGKILL);
			return 1;

		}

		for(int i = 0; i < 3; i++){

			fprintf(parent_fp, "Hello I am line %d\n", i + 1);

		}

		fflush(parent_fp);
		fclose(parent_fp);

		printf("[PARENT] -> File ready. Sleeping for 2 seconds before notifying child...\n");
		sleep(2);

		printf("[PARENT] -> Sending [DONE] SIGUSR1 signal to child (PID: %d)...\n", child_1);
		kill(child_1, SIGUSR1);

		wait(NULL);
		printf("[PARENT] -> Child finished. Program ending.\n");

	}

	return 0;

}
