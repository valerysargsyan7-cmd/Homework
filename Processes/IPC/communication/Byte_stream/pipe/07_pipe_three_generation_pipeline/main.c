#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	printf("\n\nThree-Generation Pipe Pipeline: Parent -> Child -> Grandchild\n\n");

	int fds_1[2];

	if(pipe(fds_1) == -1){

		perror("[ERROR] pipe failed");
		return 1;

	}

	pid_t pid_1 = fork();

	if(pid_1 < 0){

		perror("[ERROR] fork child failed");
		return 1;

	}

	if(pid_1 == 0){

		// CHILD (Gen 2)

		close(fds_1[1]);

		int child_val = 0;
		read(fds_1[0], &child_val, sizeof(int));
		close(fds_1[0]); 

		printf("[CHILD (Gen 2)]      -> Received value: %d from Parent.\n", child_val);

		child_val *= 2;
		printf("[CHILD (Gen 2)]      -> Doubled value: %d (* 2). Spawning Grandchild...\n", child_val);

		int fds_2[2];
		if(pipe(fds_2) == -1){

			perror("[ERROR] pipe 2 failed");
			exit(1);

		}

		pid_t pid_2 = fork();

		if(pid_2 < 0){

			perror("[ERROR] fork grandchild failed");
			close(fds_2[1]);
			exit(1);

		}

		if(pid_2 == 0){

			// GRANDCHILD (Gen 3)

			close(fds_2[1]);

			int grandchild_val = 0;
    		ssize_t bytes_read = read(fds_2[0], &grandchild_val, sizeof(int));
    		close(fds_2[0]);

    		if(bytes_read < 0){

        		perror("[GRANDCHILD ERROR] Read failed");
        		exit(1);

    		} else if (bytes_read == 0) {

        		fprintf(stderr, "[GRANDCHILD ERROR] Pipe closed unexpectedly (EOF), no data received!\n");
        		exit(1);

    		}else{

        		printf("[GRANDCHILD (Gen 3)] -> Received final pipeline payload: %d\n", grandchild_val);

    		}

			exit(0);

		}else{

			// CHILD (Gen 2)

			close(fds_2[0]); 
			
			write(fds_2[1], &child_val, sizeof(int));
			close(fds_2[1]); 

			wait(NULL);
			exit(0);

		}

	}else{

		// PARENT (Gen 1)

		close(fds_1[0]); 

		int initial_number = 5;
		printf("[PARENT (Gen 1)]     -> Sending initial seed value: %d to Child via Pipe 1...\n", initial_number);

		write(fds_1[1], &initial_number, sizeof(int));
		close(fds_1[1]);

		wait(NULL);
		printf("[PARENT (Gen 1)]     -> Entire multi-generation pipeline completed.\n");

	}

	return 0;
}