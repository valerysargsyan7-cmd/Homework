#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

void print_file_mmap(const char *filepath);

int main()
{

	printf("\n\nRead-Only File Memory Mapping (mmap)\n\n");

	const char *filepath = "sample_mmap.txt";

	FILE *fp = fopen(filepath, "w");
	if(fp != NULL){

		fprintf(fp, "Hello from Memory-Mapped file!\n"
		            "This content is mapped directly into process virtual memory with PROT_READ.\n");
		fclose(fp);

	}

	printf("Reading file '%s' via mmap():\n\n", filepath);
	print_file_mmap(filepath);

	return 0;

}

void print_file_mmap(const char *filepath)
{

	int mmap_fd = open(filepath, O_RDONLY);

	if(mmap_fd < 0){

		perror("[ERROR] Failed to open file");
		return;

	}

	off_t text_bytes = lseek(mmap_fd, 0, SEEK_END);

	if(text_bytes <= 0){

		fprintf(stderr, "[ERROR] File is empty or invalid.\n");
		close(mmap_fd);
		return;

	}

	char *addr_mmap = (char *)mmap(NULL, (size_t)text_bytes, PROT_READ, MAP_PRIVATE, mmap_fd, 0);

	if(addr_mmap == MAP_FAILED){

		perror("[ERROR] mmap failed");
		close(mmap_fd);
		return;

	}

	write(STDOUT_FILENO, addr_mmap, (size_t)text_bytes);

	munmap(addr_mmap, (size_t)text_bytes);
	close(mmap_fd);

}
