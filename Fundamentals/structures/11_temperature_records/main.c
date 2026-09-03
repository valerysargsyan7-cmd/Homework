#include <stdio.h>


struct TempRecord{

	char city[30];
	float temp;

};

int find_hottest(struct TempRecord *records, int n);
int find_coldest(struct TempRecord *records, int n);

int main()
{

	printf("\n\nThe Coldest and Hottest City\n\n");

	struct TempRecord city_info[5];

	for(int i = 0; i < 5; i++){

		printf("\nEnter name for %dth city: ", i + 1);

		if(scanf("%29s", city_info[i].city) != 1){

			printf("[ERROR] Failed to read city name!\n");
			return 1;

		}


		printf("\nEnter temperature for %dth city: ", i + 1);

		if(scanf("%f", &city_info[i].temp) != 1){

			printf("[ERROR] Invalid temperature!\n");
			return 1;

		}

	}


	int hot = find_hottest(city_info, 5);
	int cold = find_coldest(city_info, 5);

	printf("\nHottest: %.2f, CityName: %s\n",
		   city_info[hot].temp,
		   city_info[hot].city);

	printf("Coldest: %.2f, CityName: %s\n",
		   city_info[cold].temp,
		   city_info[cold].city);


	return 0;
}



int find_hottest(struct TempRecord *records, int n)
{

	int max_index = 0;

	for(int i = 1; i < n; i++){

		if(records[i].temp > records[max_index].temp){

			max_index = i;

		}

	}

	return max_index;
}


int find_coldest(struct TempRecord *records, int n)
{

	int min_index = 0;

	for(int i = 1; i < n; i++){

		if(records[i].temp < records[min_index].temp){

			min_index = i;

		}

	}

	return min_index;
}
