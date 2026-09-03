#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

volatile sig_atomic_t alloc_requested = 0;
volatile sig_atomic_t free_requested = 0;
volatile sig_atomic_t terminate_requested = 0;

void sigusr1_handler(int sig_num)
{
	(void)sig_num;
	alloc_requested = 1;
}

void sigusr2_handler(int sig_num)
{
	(void)sig_num;
	free_requested = 1;
}

void sigterm_handler(int sig_num)
{
	(void)sig_num;
	terminate_requested = 1;
}

int main()
{

	printf("\n\nSignal-Driven Remote Memory Lifecycle Manager\n\n");

	pid_t child_8 = fork();

	if(child_8 < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(child_8 == 0){

		//CHILD
		if(signal(SIGUSR1, sigusr1_handler) == SIG_ERR ||
		   signal(SIGUSR2, sigusr2_handler) == SIG_ERR ||
		   signal(SIGTERM, sigterm_handler) == SIG_ERR){

			perror("[ERROR] Signal registration failed");
			exit(1);

		}

		int *dynamic_data = NULL;
		printf("[CHILD] -> Ready. Waiting for signal memory commands...\n");

		while(!terminate_requested){

			pause();

			if(alloc_requested){

				alloc_requested = 0;
				if(dynamic_data == NULL){

					dynamic_data = (int *)malloc(1000 * sizeof(int));
					if(dynamic_data != NULL){

						printf("[CHILD] -> [SIGUSR1] 1000 ints allocated on heap (Addr: %p)\n", (void *)dynamic_data);

					}

				}else{

					printf("[CHILD] -> [SIGUSR1] Block already allocated.\n");

				}

			}

			if(free_requested){

				free_requested = 0;
				if(dynamic_data != NULL){

					free(dynamic_data);
					dynamic_data = NULL;
					printf("[CHILD] -> [SIGUSR2] Dynamic memory freed safely.\n");

				}else{

					printf("[CHILD] -> [SIGUSR2] No active memory to free.\n");

				}

			}

		}

		if(dynamic_data != NULL){

			free(dynamic_data);
			dynamic_data = NULL;

		}

		printf("[CHILD] -> [SIGTERM] Terminating cleanly.\n");
		exit(0);

	}else{

		//PARENT
		sleep(1);

		for(int i = 0; i < 3; i++){

			printf("\n--- Cycle %d ---\n", i + 1);

			printf("[PARENT] -> Sending SIGUSR1 (Allocate)...\n");
			kill(child_8, SIGUSR1);
			sleep(1);

			printf("[PARENT] -> Sending SIGUSR2 (Free)...\n");
			kill(child_8, SIGUSR2);
			sleep(1);

		}

		printf("\n[PARENT] -> Sending SIGTERM to stop child...\n");
		kill(child_8, SIGTERM);

		wait(NULL);
		printf("[PARENT] -> Child terminated cleanly. Program complete.\n");

	}

	return 0;

}
