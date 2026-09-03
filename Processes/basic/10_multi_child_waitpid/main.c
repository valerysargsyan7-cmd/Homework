#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nMulti-Child Targeted Waitpid\n\n");

	pid_t process_ids[3];

	pid_t first_pid = fork();

	if(first_pid < 0){

		perror("[ERROR] First child fork failed");
		return 1;

	}else if(first_pid == 0){

		//CHILD 1
		printf("[CHILD 1] -> Sleeping for 5 seconds...\n");
		sleep(5);
		printf("[CHILD 1] -> Finished.\n");
		exit(0);

	}else{

		process_ids[0] = first_pid;

	}

	pid_t second_pid = fork();

	if(second_pid < 0){

		perror("[ERROR] Second child fork failed");
		wait(NULL);
		return 1;

	}else if(second_pid == 0){

		//CHILD 2
		printf("[CHILD 2] -> Sleeping for 3 seconds...\n");
		sleep(3);
		printf("[CHILD 2] -> Finished.\n");
		exit(0);

	}else{

		process_ids[1] = second_pid;

	}

	pid_t third_pid = fork();

	if(third_pid < 0){

		perror("[ERROR] Third child fork failed");
		wait(NULL);
		wait(NULL);
		return 1;

	}else if(third_pid == 0){

		//CHILD 3
		printf("[CHILD 3] -> Sleeping for 1 second...\n");
		sleep(1);
		printf("[CHILD 3] -> Finished.\n");
		exit(0);

	}else{

		process_ids[2] = third_pid;

	}

	printf("\n[PARENT] -> Waiting for Child 3 (PID: %d)...\n", process_ids[2]);
	waitpid(process_ids[2], NULL, 0);
	printf("[PARENT] -> Process with %d PID reaped.\n", process_ids[2]);

	printf("\n[PARENT] -> Waiting for Child 2 (PID: %d)...\n", process_ids[1]);
	waitpid(process_ids[1], NULL, 0);
	printf("[PARENT] -> Process with %d PID reaped.\n", process_ids[1]);

	printf("\n[PARENT] -> Waiting for Child 1 (PID: %d)...\n", process_ids[0]);
	waitpid(process_ids[0], NULL, 0);
	printf("[PARENT] -> Process with %d PID reaped.\n", process_ids[0]);

	printf("\nAll 3 child processes finished.\n");

	return 0;

}
