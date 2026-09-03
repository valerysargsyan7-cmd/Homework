#include <stdio.h>

void max_min(int *mima_arr, int n, int *min, int *max);

int main()
{
	printf("\n\nMax and Min\n\n");

	int mima_arr[10];

	for(int i = 0; i < 10; i++){

		printf("Enter your %dth number: ", i + 1);

		if(scanf("%d", &mima_arr[i]) != 1){

			fprintf(stderr, "[ERROR] Invalid input at element %d.\n", i + 1);
			return 1;

		}

	}


	int max = 0;
	int min = 0;

	max_min(mima_arr, 10, &min, &max);

	printf("Min: %d\n", min);
	printf("Max: %d\n", max);


	return 0;
}


void max_min(int *mima_arr, int n, int *min, int *max)
{
	if(mima_arr == NULL || min == NULL || max == NULL || n <= 0){

		return;

	}


	*min = mima_arr[0];
	*max = mima_arr[0];


	for(int i = 1; i < n; i++){

		if(mima_arr[i] < *min){

			*min = mima_arr[i];

		}

		if(mima_arr[i] > *max){

			*max = mima_arr[i];

		}

	}
}
