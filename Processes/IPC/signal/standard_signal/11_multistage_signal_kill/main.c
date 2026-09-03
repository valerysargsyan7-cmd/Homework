#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

volatile sig_atomic_t usr1_received = 0;

void sigusr1_handler(int sig_num)
{
	(void)sig_num;
	usr1_received = 1;
}

int main()
{

	printf("\n\nMultistage Signal Delivery & Kill\n\n");

	pid_t child_proc = fork();

	if(child_proc < 0){

		perror("[ERROR] fork failed");
		return 1;

	}else if(child_proc == 0){

		//CHILD
		if(signal(SIGUSR1, sigusr1_handler) == SIG_ERR){

			perror("[ERROR] signal registration failed");
			exit(1);

		}

		printf("[CHILD] -> Running and waiting for signals...\n");

		while(1){

			if(usr1_received){

				printf("\n[HANDLER] -> Child received USR1 signal!\n");
				usr1_received = 0;

			}

			sleep(1);

		}

	}else{

		//PARENT
		sleep(2);

		printf("\n[PARENT] -> Sending SIGUSR1 to child...\n");
		kill(child_proc, SIGUSR1);

		sleep(2);

		printf("[PARENT] -> Sending SIGKILL to child...\n");
		kill(child_proc, SIGKILL);

		int status;
		wait(&status);

		if(WIFSIGNALED(status)){

			printf("\n[PARENT] -> Child was terminated by signal: %d\n", WTERMSIG(status));

		}

		printf("[PARENT] -> Program finished.\n");

	}

	return 0;

}
