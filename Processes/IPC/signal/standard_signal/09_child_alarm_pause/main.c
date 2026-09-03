#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

volatile sig_atomic_t child_alarm_fired = 0;

void alarm_handler_6(int sig_num)
{
	(void)sig_num;
	child_alarm_fired = 1;
}

int main()
{

	printf("\n\nChild Alarm Pause\n\n");

	pid_t child_proc = fork();

	if(child_proc < 0){

		perror("[ERROR] fork failed");
		return 1;

	}else if(child_proc == 0){

		//CHILD
		if(signal(SIGALRM, alarm_handler_6) == SIG_ERR){

			perror("[ERROR] signal registration failed");
			exit(1);

		}

		printf("[CHILD] -> Setting alarm for 2 seconds and pausing...\n");
		alarm(2);
		pause();

		if(child_alarm_fired){

			printf("\n[HANDLER] -> Alarm in child fired!\n");

		}

		exit(0);

	}else{

		//PARENT
		wait(NULL);
		printf("\n[PARENT] -> Parent caught child exit. Done.\n");

	}

	return 0;

}
