#include <stdio.h>

struct Employee {

	char name[50];
	unsigned int salaries[6];
	int average;

};

int employee_info_input(struct Employee employees[], int employees_quantity);
int largest_average_counting(struct Employee employees[], int employees_quantity);
void info_output(struct Employee employee);

int main()
{
	printf("\n\nEmployees DataBase\n\n");

	int employees_quantity = 3;

	struct Employee employees[3];


	printf("Info input\n");

	if(employee_info_input(employees, employees_quantity) != 0){

		return 1;

	}


	int best_index = largest_average_counting(
		employees,
		employees_quantity
	);


	if(best_index == -1){

		fprintf(stderr, "[ERROR] Failed to find employee.\n");
		return 1;

	}


	info_output(employees[best_index]);


	return 0;
}




int employee_info_input(struct Employee employees[], int employees_quantity)
{
	for(int i = 0; i < employees_quantity; i++){

		printf("\nEnter %dth Employee's name: ", i + 1);

		if(scanf("%49s", employees[i].name) != 1){

			fprintf(stderr, "[ERROR] Failed to read employee's name.\n");
			return 1;

		}


		for(int j = 0; j < 6; j++){

			printf("Enter %dth Employee's %d salary: ",
			       i + 1,
			       j + 1);

			if(scanf("%u", &employees[i].salaries[j]) != 1){

				fprintf(stderr, "[ERROR] Invalid salary for employee %d.\n",
				        i + 1);
				return 1;

			}

		}
	}


	return 0;
}


int largest_average_counting(struct Employee employees[], int employees_quantity)
{
	if(employees == NULL || employees_quantity <= 0){

		return -1;

	}


	int max_average = 0;


	for(int i = 0; i < employees_quantity; i++){

		unsigned long long sum = 0;


		for(int j = 0; j < 6; j++){

			sum += employees[i].salaries[j];

		}


		employees[i].average = (int)(sum / 6);


		if(employees[i].average > employees[max_average].average){

			max_average = i;

		}

	}


	return max_average;
}


void info_output(struct Employee employee)
{
	printf("\n\nEmployee information\n\n");

	printf("Name: %s\n", employee.name);


	for(int i = 0; i < 6; i++){

		printf("%dth Salary: %u\n",
		       i + 1,
		       employee.salaries[i]);

	}


	printf("Average: %d\n", employee.average);
}
