#include <stdio.h>

int power_of_num(int x, int n);

int main()
{
	printf("\n\nPower\n\n");

	int num_for_power = 0;
	int power = 0;

	printf("\nEnter number for power: ");

	if(scanf("%d", &num_for_power) != 1){

		printf("[ERROR] Invalid number input!\n");
		return 1;

	}


	printf("\nEnter power for number: ");

	if(scanf("%d", &power) != 1){

		printf("[ERROR] Invalid power input!\n");
		return 1;

	}


	if(power < 0){

		printf("[ERROR] Power cannot be negative!\n");
		return 1;

	}


	printf("\n%d number's %d power is: %d\n",
		   num_for_power,
		   power,
		   power_of_num(num_for_power, power));


	return 0;
}



int power_of_num(int x, int n)
{

	if(n == 0){

		return 1;

	}


	return x * power_of_num(x, n - 1);

}
