#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t parent_pgid;
volatile sig_atomic_t ch5_sig_count = 0;
volatile sig_atomic_t ch6_sig_count = 0;

void sigusr1_handler_ch_5(int sig_num)
{
	(void)sig_num;
	ch5_sig_count++;
	setpgid(0, parent_pgid);
}

void sigusr1_handler_ch_6(int sig_num)
{
	(void)sig_num;
	ch6_sig_count++;
}

int main()
{

	printf("\n\nProcess Group Signal Broadcast & Migration\n\n");

	parent_pgid = getpgrp();

	pid_t child_5 = fork();

	if(child_5 < 0){

		perror("[ERROR] fork child 5 failed");
		return 1;

	}

	if(child_5 == 0){

		//CHILD 5
		printf("[CHILD 5] -> Born (PID: %d)\n", getpid());

		if(signal(SIGUSR1, sigusr1_handler_ch_5) == SIG_ERR){

			perror("[ERROR] signal failed");
			exit(1);

		}

		while(1){

			pause();

			if(ch5_sig_count > 0){

				printf("[CHILD 5] -> Handled SIGUSR1 (migrated back to parent PGID %d)!\n", parent_pgid);
				ch5_sig_count = 0;

			}

		}

	}else{

		pid_t child_6 = fork();

		if(child_6 < 0){

			perror("[ERROR] fork child 6 failed");
			kill(child_5, SIGKILL);
			return 1;

		}

		if(child_6 == 0){

			//CHILD 6
			printf("[CHILD 6] -> Born (PID: %d)\n", getpid());

			if(signal(SIGUSR1, sigusr1_handler_ch_6) == SIG_ERR){

				perror("[ERROR] signal failed");
				exit(1);

			}

			while(1){

				pause();

				if(ch6_sig_count > 0){

					printf("[CHILD 6] -> Handled SIGUSR1 (remains in PGID %d)!\n", child_5);
					ch6_sig_count = 0;

				}

			}

		}else{

			//PARENT sets group for child_5 and child_6
			setpgid(child_5, child_5);
			setpgid(child_6, child_5);

			sleep(1);

			printf("\n[PARENT] -> Broadcasting 1st SIGUSR1 to Process Group %d via killpg()...\n", child_5);
			killpg(child_5, SIGUSR1);

			sleep(1);

			printf("\n[PARENT] -> Broadcasting 2nd SIGUSR1 to Process Group %d (only Child 6 remains)...\n", child_5);
			killpg(child_5, SIGUSR1);

			sleep(2);

			printf("\n[PARENT] -> Cleaning up children with SIGKILL...\n");
			kill(child_5, SIGKILL);
			kill(child_6, SIGKILL);

			wait(NULL);
			wait(NULL);

			printf("[PARENT] -> Both children finished.\n");

		}

	}

	return 0;

}
