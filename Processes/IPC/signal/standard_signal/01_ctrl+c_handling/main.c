#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ctrlc_handler(int sig_num);
volatile sig_atomic_t ctrlc_flag = 0;

int main()
{
	printf("\n\nCtrl+C Handling\n\n");

	if(signal(SIGINT, ctrlc_handler) == SIG_ERR){

		perror("[ERROR] signal failed");
		return 1;

	}

	printf("Press Ctrl+C to test the handler.\n");

	while(1){

		if(ctrlc_flag){

			printf("\nYou've just pressed Ctrl+C\n");
			ctrlc_flag = 0;

		}

		sleep(1);
	}

	return 0;
}

void ctrlc_handler(int sig_num)
{
	(void)sig_num;
	ctrlc_flag = 1;
}