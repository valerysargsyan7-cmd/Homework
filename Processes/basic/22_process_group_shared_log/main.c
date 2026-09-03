#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nProcess Group Shared File Logging\n\n");

	const char *group_filename = "group_log.txt";

	int group_fd = open(group_filename, O_RDWR | O_CREAT | O_TRUNC, 0644);

	if(group_fd < 0){

		perror("[ERROR] Failed to open group log file");
		return 1;

	}

	pid_t child_2 = fork();

	if(child_2 < 0){

		perror("[ERROR] fork child 2 failed");
		close(group_fd);
		return 1;

	}

	if(child_2 == 0){

		//CHILD 2
		int ch_2_fd = open(group_filename, O_WRONLY | O_APPEND);
		if(ch_2_fd >= 0){

			char ch_2_buf[64];
			snprintf(ch_2_buf, sizeof(ch_2_buf), "[CHILD_2] -> worked (PID: %d)\n", getpid());
			write(ch_2_fd, ch_2_buf, strlen(ch_2_buf));
			sleep(1);
			close(ch_2_fd);

		}
		exit(0);

	}else{

		pid_t child_3 = fork();

		if(child_3 < 0){

			perror("[ERROR] fork child 3 failed");
			wait(NULL);
			close(group_fd);
			return 1;

		}

		if(child_3 == 0){

			//CHILD 3
			int ch_3_fd = open(group_filename, O_WRONLY | O_APPEND);
			if(ch_3_fd >= 0){

				char ch_3_buf[64];
				snprintf(ch_3_buf, sizeof(ch_3_buf), "[CHILD_3] -> worked (PID: %d)\n", getpid());
				write(ch_3_fd, ch_3_buf, strlen(ch_3_buf));
				sleep(1);
				close(ch_3_fd);

			}
			exit(0);

		}else{

			pid_t child_4 = fork();

			if(child_4 < 0){

				perror("[ERROR] fork child 4 failed");
				wait(NULL);
				wait(NULL);
				close(group_fd);
				return 1;

			}

			if(child_4 == 0){

				//CHILD 4
				int ch_4_fd = open(group_filename, O_WRONLY | O_APPEND);
				if(ch_4_fd >= 0){

					char ch_4_buf[64];
					snprintf(ch_4_buf, sizeof(ch_4_buf), "[CHILD_4] -> worked (PID: %d)\n", getpid());
					write(ch_4_fd, ch_4_buf, strlen(ch_4_buf));
					sleep(1);
					close(ch_4_fd);

				}
				exit(0);

			}else{

				//PARENT
				setpgid(child_2, child_2);
				setpgid(child_3, child_2);
				setpgid(child_4, child_2);

				printf("[PARENT] -> Group generation (PGID: %d)...\n", child_2);

				wait(NULL);
				printf("[PARENT] -> First child status: DONE\n");

				wait(NULL);
				printf("[PARENT] -> Second child status: DONE\n");

				wait(NULL);
				printf("[PARENT] -> Third child status: DONE\n");

				close(group_fd);

				FILE *fp_parent = fopen(group_filename, "r");

				if(fp_parent != NULL){

					char parent_buf[256];
					printf("\n--- Group Log Content (%s) ---\n", group_filename);
					while(fgets(parent_buf, sizeof(parent_buf), fp_parent)){

						printf("%s", parent_buf);

					}
					fclose(fp_parent);

				}

			}

		}

	}

	return 0;

}
