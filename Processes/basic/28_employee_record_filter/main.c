#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

struct Employee {
	int id;
	char name[20];
	double salary;
};

void form_filling_function(struct Employee *arr, int size);

int main()
{

	printf("\n\nBinary Employee Record Serialization & Filtering\n\n");

	const char *bin_filename = "employees.bin";
	int count = 3;

	struct Employee *employer = (struct Employee *)malloc((size_t)count * sizeof(struct Employee));

	if(employer == NULL){

		perror("[ERROR] malloc failed in parent");
		return 1;

	}

	form_filling_function(employer, count);

	FILE *employees_fp = fopen(bin_filename, "wb");

	if(employees_fp == NULL){

		perror("[ERROR] Failed to open employees.bin");
		free(employer);
		return 1;

	}

	size_t written = fwrite(employer, sizeof(struct Employee), (size_t)count, employees_fp);
	fclose(employees_fp);
	free(employer);

	if(written != (size_t)count){

		fprintf(stderr, "[ERROR] Failed to write all employee records.\n");
		return 1;

	}

	printf("\n[PARENT] -> Saved %zu employee records to '%s'.\n", written, bin_filename);

	pid_t child_7 = fork();

	if(child_7 < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(child_7 == 0){

		//CHILD
		FILE *ch_7_fp = fopen(bin_filename, "rb");

		if(ch_7_fp == NULL){

			perror("[ERROR] Child fopen failed");
			exit(1);

		}

		fseek(ch_7_fp, 0, SEEK_END);
		long bytes = ftell(ch_7_fp);
		rewind(ch_7_fp);

		if(bytes <= 0 || (size_t)bytes < sizeof(struct Employee)){

			fprintf(stderr, "[ERROR] Invalid or empty employee binary file.\n");
			fclose(ch_7_fp);
			exit(1);

		}

		size_t workers = (size_t)bytes / sizeof(struct Employee);
		struct Employee *child_array = (struct Employee *)calloc(workers, sizeof(struct Employee));

		if(child_array == NULL){

			perror("[ERROR] calloc failed in child");
			fclose(ch_7_fp);
			exit(1);

		}

		size_t read_count = fread(child_array, sizeof(struct Employee), workers, ch_7_fp);
		fclose(ch_7_fp);

		printf("\n[CHILD] -> Read %zu employee records. Filtering (Salary > $100,000):\n", read_count);
		printf("------------------------------------------------------------\n");

		int matches = 0;
		for(size_t i = 0; i < workers; i++){

			if(child_array[i].salary > 100000.0){

				printf("ID: %-4d | Name: %-15s | Salary: $%.2lf\n",
				       child_array[i].id, child_array[i].name, child_array[i].salary);
				matches++;

			}

		}

		if(matches == 0){

			printf("No employees meet the > $100,000 threshold.\n");

		}
		printf("------------------------------------------------------------\n");

		free(child_array);
		exit(0);

	}else{

		//PARENT
		wait(NULL);
		printf("[PARENT] -> Child filtering complete.\n");

	}

	return 0;

}

void form_filling_function(struct Employee *arr, int size)
{

	printf("Enter data for %d employees:\n", size);

	for(int i = 0; i < size; i++){

		printf("\nEnter Employee %d ID: ", i + 1);
		if(scanf("%d", &arr[i].id) != 1){

			arr[i].id = i + 1;

		}

		printf("Enter Employee %d Name: ", i + 1);
		if(scanf("%19s", arr[i].name) != 1){

			strncpy(arr[i].name, "Unknown", 20);

		}

		printf("Enter Employee %d Salary: ", i + 1);
		if(scanf("%lf", &arr[i].salary) != 1){

			arr[i].salary = 0.0;

		}

	}

}
