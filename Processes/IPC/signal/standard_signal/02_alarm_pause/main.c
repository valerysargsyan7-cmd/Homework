#include <stdio.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t alarm_flag = 0;

void alarm_handler(int sig_num)
{
	(void)sig_num;
	alarm_flag = 1;
}

int main()
{
	printf("\n\nAlarm Pause\n\n");

	if(signal(SIGALRM, alarm_handler) == SIG_ERR){

		perror("[ERROR] signal failed");
		return 1;
	}

	printf("Waiting for alarm...\n");

	alarm(4);

	pause();

	if(alarm_flag){

		printf("\nTime is up!\n");
		alarm_flag = 0;

	}

	printf("Program finished.\n");
	
	return 0;
}