#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t alarm_triggered = 0;

void alarm_handler(int sig_num)
{
	(void)sig_num;
	alarm_triggered = 1;
}

int main()
{

	printf("\n\nImmortal Process with Alarm Timeout\n\n");
	printf("Blocking SIGINT (Ctrl+C). Try pressing Ctrl+C...\n");
	printf("An alarm is set for 5 seconds to terminate the process.\n");

	sigset_t blocking_set;

	if(sigemptyset(&blocking_set) == -1 ||
	   sigaddset(&blocking_set, SIGINT) == -1 ||
	   sigprocmask(SIG_BLOCK, &blocking_set, NULL) == -1){

		perror("[ERROR] Signal mask configuration failed");
		return 1;

	}

	if(signal(SIGALRM, alarm_handler) == SIG_ERR){

		perror("[ERROR] Signal registration failed");
		return 1;

	}

	alarm(5);

	while(!alarm_triggered){

		pause();

	}

	printf("\nTime limit reached. Exiting cleanly...\n");

	return 0;

}
