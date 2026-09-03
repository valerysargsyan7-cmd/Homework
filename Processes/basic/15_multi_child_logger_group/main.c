#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nMulti-Child Logger Group\n\n");

	const char *log_file = "audit.log";

	int fd = open(log_file, O_CREAT | O_RDWR | O_APPEND | O_TRUNC, 0644);

	if(fd < 0){

		perror("[ERROR] Failed to open audit.log");
		return 1;

	}

	pid_t child_12;
	pid_t child_13;
	pid_t child_14;

	child_12 = fork();

	if(child_12 < 0){

		perror("[ERROR] fork child 12 failed");
		close(fd);
		return 1;

	}

	if(child_12 == 0){

		//CHILD 12
		for(int i = 0; i < 3; i++){

			sleep(1);
			write(fd, "[1_CHILD] -> Running...\n", 24);

		}

		close(fd);
		exit(0);

	}else{

		child_13 = fork();

		if(child_13 < 0){

			perror("[ERROR] fork child 13 failed");
			kill(child_12, SIGKILL);
			close(fd);
			return 1;

		}

		if(child_13 == 0){

			//CHILD 13
			for(int i = 0; i < 3; i++){

				sleep(1);
				write(fd, "[2_CHILD] -> Running...\n", 24);

			}

			close(fd);
			exit(0);

		}else{

			child_14 = fork();

			if(child_14 < 0){

				perror("[ERROR] fork child 14 failed");
				kill(child_12, SIGKILL);
				kill(child_13, SIGKILL);
				close(fd);
				return 1;

			}

			if(child_14 == 0){

				//CHILD 14
				for(int i = 0; i < 3; i++){

					sleep(1);
					write(fd, "[3_CHILD] -> Running...\n", 24);

				}

				close(fd);
				exit(0);

			}else{

				//PARENT
				setpgid(child_12, child_12);
				setpgid(child_13, child_12);
				setpgid(child_14, child_12);

				printf("[PARENT] -> Loggers started in process group %d.\n", child_12);

				for(int i = 0; i < 3; i++){

					wait(NULL);

				}

				close(fd);

				printf("\n[PARENT] -> All logger children finished.\n");

				FILE *fp = fopen(log_file, "r");
				if(fp != NULL){

					char line[64];
					printf("\n--- Audit Log Content (%s) ---\n", log_file);
					while(fgets(line, sizeof(line), fp)){

						printf("%s", line);

					}
					fclose(fp);

				}

			}

		}

	}

	return 0;

}
