#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{

	printf("\n\nPrivate vs Shared Mmap (Copy-On-Write Demonstration)\n\n");

	const char *filepath = "cow_sample.txt";

	FILE *fp = fopen(filepath, "w");
	if(fp != NULL){

		fprintf(fp, "0123456789\n");
		fclose(fp);

	}

	int fd = open(filepath, O_RDWR);

	if(fd < 0){

		perror("[ERROR] Failed to open file");
		return 1;

	}

	off_t text_bytes = lseek(fd, 0, SEEK_END);

	char *shared_ptr = (char *)mmap(NULL, (size_t)text_bytes, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	char *private_ptr = (char *)mmap(NULL, (size_t)text_bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

	if(shared_ptr == MAP_FAILED || private_ptr == MAP_FAILED){

		perror("[ERROR] mmap failed");
		close(fd);
		return 1;

	}

	printf("Initial file content: \"0123456789\"\n\n");

	printf("Writing '#' to index 0 of MAP_PRIVATE pointer...\n");
	private_ptr[0] = '#';

	printf("Writing '*' to index 1 of MAP_SHARED pointer...\n\n");
	shared_ptr[1] = '*';

	printf("Contents from MAP_PRIVATE pointer: \"%s\"\n", private_ptr);
	printf("Contents from MAP_SHARED pointer:  \"%s\"\n", shared_ptr);

	munmap(shared_ptr, (size_t)text_bytes);
	munmap(private_ptr, (size_t)text_bytes);
	close(fd);

	FILE *vfp = fopen(filepath, "r");
	if(vfp != NULL){

		char line[32];
		if(fgets(line, sizeof(line), vfp)){

			printf("\nFinal content on DISK: \"%s\"\n", line);
			printf("Explanation: MAP_SHARED change ('*') was written to disk.\n"
			       "             MAP_PRIVATE change ('#') remained in private process page (COW).\n");

		}
		fclose(vfp);

	}

	return 0;

}
