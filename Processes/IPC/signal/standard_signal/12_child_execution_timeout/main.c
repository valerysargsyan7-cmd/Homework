#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

pid_t child_pid;

void alrm_handler(int sig_num)
{
	(void)sig_num;
	printf("\n[WATCHDOG] -> Child process exceeded time limit and was killed\n");
	kill(child_pid, SIGKILL);
}

int main()
{

	printf("\n\nChild Execution Timeout (Watchdog)\n\n");

	child_pid = fork();

	if(child_pid < 0){

		perror("[ERROR] fork failed");
		return 1;

	}else if(child_pid == 0){

		//CHILD
		printf("[CHILD] -> Starting task (sleep 10)...\n");
		execlp("sleep", "sleep", "10", NULL);
		perror("[ERROR] execlp failed");
		exit(1);

	}else{

		//PARENT
		if(signal(SIGALRM, alrm_handler) == SIG_ERR){

			perror("[ERROR] signal registration failed");
			kill(child_pid, SIGKILL);
			return 1;

		}

		printf("[PARENT] -> Started child PID %d. Setting alarm for 3 seconds...\n", child_pid);
		alarm(3);

		int status;
		wait(&status);

		if(WIFSIGNALED(status)){

			printf("[PARENT] -> Child was terminated by signal: %d\n", WTERMSIG(status));

		}

		printf("[PARENT] -> Watchdog monitoring finished.\n");

	}

	return 0;

}
