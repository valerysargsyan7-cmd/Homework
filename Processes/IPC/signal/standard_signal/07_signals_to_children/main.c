#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

volatile sig_atomic_t first_child_sig = 0;
volatile sig_atomic_t second_child_sig = 0;

void first_child_handler(int sig_num)
{
	(void)sig_num;
	first_child_sig = 1;
}

void second_child_handler(int sig_num)
{
	(void)sig_num;
	second_child_sig = 1;
}

int main()
{

	printf("\n\nSignals to Multiple Children\n\n");

	pid_t first_child = fork();

	if(first_child < 0){

		perror("[ERROR] First child fork failed");
		return 1;

	}else if(first_child == 0){

		//FIRST CHILD
		if(signal(SIGUSR1, first_child_handler) == SIG_ERR){

			perror("[ERROR] First child signal registration failed");
			exit(1);

		}

		pause();

		if(first_child_sig){

			printf("[FIRST CHILD] -> I got SIGUSR1 signal!\n");

		}

		exit(0);

	}else{

		pid_t second_child = fork();

		if(second_child < 0){

			perror("[ERROR] Second child fork failed");
			return 1;

		}else if(second_child == 0){

			//SECOND CHILD
			if(signal(SIGUSR2, second_child_handler) == SIG_ERR){

				perror("[ERROR] Second child signal registration failed");
				exit(1);

			}

			pause();

			if(second_child_sig){

				printf("[SECOND CHILD] -> I got SIGUSR2 signal!\n");

			}

			exit(0);

		}else{

			//PARENT
			sleep(1);

			printf("\n[PARENT] -> Sending SIGUSR1 to first child...\n");
			kill(first_child, SIGUSR1);

			printf("[PARENT] -> Sending SIGUSR2 to second child...\n");
			kill(second_child, SIGUSR2);

			wait(NULL);
			wait(NULL);

			printf("\n[PARENT] -> Both children finished work.\n");

		}

	}

	return 0;

}
