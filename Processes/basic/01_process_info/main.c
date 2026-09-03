#include <stdio.h>
#include <unistd.h>

int main()
{

	printf("\n\nProcess Information\n\n");

	printf("Process ID: %d\n", getpid());
	printf("Parent Process ID: %d\n", getppid());
	printf("Process Group ID: %d\n", getpgrp());


	return 0;

}