#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

volatile sig_atomic_t sigusr1_received = 0;

void sigusr1_handler(int sig_num)
{
	(void)sig_num;
	sigusr1_received = 1;
}

void reversing_string(char *string);

int main()
{

	printf("\n\nSignal-Synchronized String Reversal Pipeline\n\n");

	const char *word[] = {"Apple\n", "Banana\n", "Cherry\n"};
	const char *word_filename = "words.txt";
	const char *reversed_filename = "reversed.txt";

	int word_fd = open(word_filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if(word_fd < 0){

		perror("[ERROR] Failed to open words.txt");
		return 1;

	}

	for(int i = 0; i < 3; i++){

		write(word_fd, word[i], strlen(word[i]));

	}

	close(word_fd);

	pid_t child_3 = fork();

	if(child_3 < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(child_3 == 0){

		//CHILD
		if(signal(SIGUSR1, sigusr1_handler) == SIG_ERR){

			perror("[ERROR] signal failed");
			exit(1);

		}

		printf("[CHILD] -> Waiting for SIGUSR1 signal from PARENT...\n");

		while(!sigusr1_received){

			pause();

		}

		FILE *child_word_fp = fopen(word_filename, "r");
		if(child_word_fp == NULL){

			perror("[ERROR] Failed to open words.txt in child");
			exit(1);

		}

		FILE *reversed_fp = fopen(reversed_filename, "w");
		if(reversed_fp == NULL){

			perror("[ERROR] Failed to open reversed.txt");
			fclose(child_word_fp);
			exit(1);

		}

		char child_buffer[128];

		while(fgets(child_buffer, sizeof(child_buffer), child_word_fp)){

			size_t len = strlen(child_buffer);
			if(len > 0 && child_buffer[len - 1] == '\n'){

				child_buffer[len - 1] = '\0';
				len--;

			}

			char *dynamic_word = (char *)malloc(len + 1);
			if(dynamic_word != NULL){

				strcpy(dynamic_word, child_buffer);
				reversing_string(dynamic_word);
				fprintf(reversed_fp, "%s\n", dynamic_word);
				printf("[CHILD] -> Transformed: '%s' -> '%s'\n", child_buffer, dynamic_word);
				free(dynamic_word);

			}

		}

		fclose(reversed_fp);
		fclose(child_word_fp);

		printf("\n[CHILD] -> Program Status: DONE (Saved to '%s')\n", reversed_filename);
		exit(0);

	}else{

		//PARENT
		printf("[PARENT] -> Words written to '%s'. Sending SIGUSR1 to child (PID: %d)...\n",
		       word_filename, child_3);
		sleep(1);
		kill(child_3, SIGUSR1);

		wait(NULL);

		FILE *fp_rev = fopen(reversed_filename, "r");
		if(fp_rev != NULL){

			char line[128];
			printf("\n--- Reversed File Content (%s) ---\n", reversed_filename);
			while(fgets(line, sizeof(line), fp_rev)){

				printf("%s", line);

			}
			fclose(fp_rev);

		}

		printf("[PARENT] -> Program complete.\n");

	}

	return 0;

}

void reversing_string(char *string)
{

	if(string == NULL){

		return;

	}

	char *start = string;
	char *end = string;

	while(*end != '\0'){

		end++;

	}

	if(end > start){

		end--;

	}

	while(end > start){

		char temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;

	}

}
