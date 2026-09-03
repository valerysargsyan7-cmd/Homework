#include <stdio.h>


struct Vehicle {

	char brand[30];
	int year;
	float fuel;

};

void fill_tank(struct Vehicle *v, float amount);
void driver(struct Vehicle *v, int km);
void print_vehicle(struct Vehicle v);


int main()
{

	printf("\n\nVehicle\n\n");

	printf("\nEntering vehicle info\n");

	struct Vehicle Car;

	printf("\nEnter your Vehicle brand: ");

	if(scanf("%29s", Car.brand) != 1){

		printf("[ERROR] Failed to read vehicle brand!\n");
		return 1;

	}


	printf("\nEnter your Vehicle year: ");

	if(scanf("%d", &Car.year) != 1){

		printf("[ERROR] Invalid year!\n");
		return 1;

	}


	printf("\nEnter your Vehicle fuel: ");

	if(scanf("%f", &Car.fuel) != 1){

		printf("[ERROR] Invalid fuel amount!\n");
		return 1;

	}


	if(Car.fuel < 0.0f || Car.fuel > 60.0f){

		printf("[ERROR] Fuel must be between 0 and 60!\n");
		return 1;

	}


	float amount = 0.0f;

	printf("\nEnter amount to fill your fuel: ");

	if(scanf("%f", &amount) != 1){

		printf("[ERROR] Invalid fuel amount!\n");
		return 1;

	}


	fill_tank(&Car, amount);


	int km = 0;

	printf("\nEnter distance: ");

	if(scanf("%d", &km) != 1){

		printf("[ERROR] Invalid distance!\n");
		return 1;

	}


	if(km < 0){

		printf("[ERROR] Distance cannot be negative!\n");
		return 1;

	}


	driver(&Car, km);

	print_vehicle(Car);


	return 0;
}



void fill_tank(struct Vehicle *v, float amount)
{

	if(amount < 0){

		printf("\n[ERROR] Fuel amount cannot be negative!\n");
		return;

	}


	if(amount + v->fuel > 60.0f){

		printf("\n[ERROR] Too much fuel!\n");

	}else{

		v->fuel += amount;

	}

}


void driver(struct Vehicle *v, int km)
{

	for(int i = 0; i < km; i++){

		if(v->fuel >= 0.08f){

			v->fuel -= 0.08f;

		}else{

			printf("\n[ERROR] No fuel!\n");
			break;

		}

	}

}


void print_vehicle(struct Vehicle v)
{

	printf("\nFuel left: %.2f\n", v.fuel);

}