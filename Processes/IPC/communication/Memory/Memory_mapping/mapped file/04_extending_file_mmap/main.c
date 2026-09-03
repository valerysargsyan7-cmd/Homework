#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

int main()
{

	printf("\n\nExtending File Size via Ftruncate & Mmap\n\n");

	const char *filepath = "extended_data.txt";
	size_t target_size = 1024;

	int fd = open(filepath, O_CREAT | O_RDWR | O_TRUNC, 0644);

	if(fd < 0){

		perror("[ERROR] Failed to create file");
		return 1;

	}

	printf("Initial file created (0 bytes).\n");

	if(ftruncate(fd, (off_t)target_size) == -1){

		perror("[ERROR] ftruncate failed");
		close(fd);
		return 1;

	}

	printf("File capacity extended to %zu bytes using ftruncate().\n", target_size);

	char *ext_file = (char *)mmap(NULL, target_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	if(ext_file == MAP_FAILED){

		perror("[ERROR] mmap failed");
		close(fd);
		return 1;

	}

	const char *message = "This file was extended using ftruncate and populated via mmap!";
	strcpy(ext_file, message);

	printf("Written string to extended memory map: \"%s\"\n", ext_file);

	munmap(ext_file, target_size);
	close(fd);

	FILE *fp = fopen(filepath, "r");
	if(fp != NULL){

		char line[128];
		if(fgets(line, sizeof(line), fp)){

			printf("\nRead back from disk: \"%s\"\n", line);

		}
		fclose(fp);

	}

	return 0;

}
