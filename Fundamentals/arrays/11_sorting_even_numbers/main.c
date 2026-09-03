#include <stdio.h>

int main()
{

	printf("\n\nSorting Even Numbers\n\n");

	int nums[5];


	for(int i = 0; i < 5; i++){

		printf("Enter %dth number for array: ", i + 1);

		if(scanf("%d", &nums[i]) != 1){

			printf("\n[ERROR] Invalid input!\n");
			return 1;

		}

	}


	int start = 0;
	int end = 4;


	while(start < end){

		if(nums[start] % 2 == 0){

			start++;

		}else if(nums[end] % 2 != 0){

			end--;

		}else{

			int temp = nums[start];

			nums[start] = nums[end];
			nums[end] = temp;

			start++;
			end--;

		}

	}


	printf("\nEven numbers moved to the beginning:\n\n");


	for(int i = 0; i < 5; i++){

		printf("%d ", nums[i]);

	}


	printf("\n");


	return 0;

}