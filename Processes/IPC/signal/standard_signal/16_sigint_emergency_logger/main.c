#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

void sigint_handler(int sig_num)
{
	(void)sig_num;
	int fd = open("SIGINT_info.txt", O_CREAT | O_RDWR | O_APPEND, 0644);
	if(fd >= 0){

		write(fd, "[CRITICAL] Emergency stop applied!\n", 35);
		close(fd);

	}

	const char msg[] = "\n[CRITICAL] Emergency stop applied! Logged to SIGINT_info.txt.\n";
	write(STDOUT_FILENO, msg, sizeof(msg) - 1);
	_exit(0);
}

int main()
{

	printf("\n\nSIGINT Emergency Logger\n\n");
	printf("Running... Press Ctrl+C to trigger emergency stop logging.\n");

	if(signal(SIGINT, sigint_handler) == SIG_ERR){

		perror("[ERROR] signal failed");
		return 1;

	}

	while(1){

		pause();

	}

	return 0;

}
