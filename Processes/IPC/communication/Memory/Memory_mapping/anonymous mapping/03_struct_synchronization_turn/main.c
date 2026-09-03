#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

struct State {
	volatile int turn;
	volatile int value;
};

struct State *mmap_obj(void);

int main()
{

	printf("\n\nInter-Process Shared Struct Turn Synchronization\n\n");

	struct State *sha_obj = mmap_obj();

	if(sha_obj == NULL){

		fprintf(stderr, "[ERROR] Failed to allocate shared struct.\n");
		return 1;

	}

	sha_obj->turn = 0;
	sha_obj->value = 1;

	printf("Initial State: turn = %d, value = %d\n\n", sha_obj->turn, sha_obj->value);

	pid_t pid_1 = fork();

	if(pid_1 < 0){

		perror("[ERROR] fork failed");
		munmap(sha_obj, sizeof(struct State));
		return 1;

	}

	if(pid_1 == 0){

		//CHILD
		for(int i = 0; i < 5; i++){

			while(sha_obj->turn != 0){

				usleep(1000);

			}

			sha_obj->value *= 2;
			printf("[CHILD  (Step %d/5)] -> value (* 2) = %d\n", i + 1, sha_obj->value);

			sha_obj->turn = 1;

		}

		exit(0);

	}else{

		//PARENT
		for(int i = 0; i < 5; i++){

			while(sha_obj->turn != 1){

				usleep(1000);

			}

			sha_obj->value *= 3;
			printf("[PARENT (Step %d/5)] -> value (* 3) = %d\n", i + 1, sha_obj->value);

			sha_obj->turn = 0;

		}

		wait(NULL);

		printf("\nFinal Shared State value = %d\n", sha_obj->value);
		munmap(sha_obj, sizeof(struct State));
		printf("Shared struct unmapped cleanly.\n");

	}

	return 0;

}

struct State *mmap_obj(void)
{

	struct State *object = (struct State *)mmap(NULL, sizeof(struct State),
	                                            PROT_READ | PROT_WRITE,
	                                            MAP_SHARED | MAP_ANONYMOUS,
	                                            -1, 0);

	if(object == MAP_FAILED){

		perror("[ERROR] mmap anonymous failed");
		return NULL;

	}

	return object;

}
