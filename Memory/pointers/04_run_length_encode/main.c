#include <stdio.h>
#include <string.h>

void my_strcpy(char *dest, const char *src);
void run_length_encode(char *input, char *output);

int main()
{

	printf("\n\nRun Length Encode\n\n");

	char strcp_1[100];
	char strcp_output_1[200];

	printf("\nEnter symbols to count for first: ");

	if(scanf("%99s", strcp_1) != 1){

		printf("[ERROR] Failed to read first string!\n");
		return 1;

	}


	char strcp_2[100];
	char strcp_output_2[200];

	printf("\nEnter symbols to count for second: ");

	if(scanf("%99s", strcp_2) != 1){

		printf("[ERROR] Failed to read second string!\n");
		return 1;

	}


	char strcp_3[100];
	char strcp_output_3[200];

	printf("\nEnter symbols to count for third: ");

	if(scanf("%99s", strcp_3) != 1){

		printf("[ERROR] Failed to read third string!\n");
		return 1;

	}


	run_length_encode(strcp_1, strcp_output_1);
	run_length_encode(strcp_2, strcp_output_2);
	run_length_encode(strcp_3, strcp_output_3);


	printf("\nBefore counting: %s\n", strcp_1);
	printf("After counting: %s\n", strcp_output_1);

	printf("\nBefore counting: %s\n", strcp_2);
	printf("After counting: %s\n", strcp_output_2);

	printf("\nBefore counting: %s\n", strcp_3);
	printf("After counting: %s\n", strcp_output_3);


	return 0;
}




void my_strcpy(char *dest, const char *src)
{

	while(*src != '\0'){

		*dest = *src;
		dest++;
		src++;

	}

	*dest = '\0';

}


void run_length_encode(char *input, char *output)
{

	char tmp_arr[100];

	my_strcpy(tmp_arr, input);

	input = tmp_arr;

	while(*input != '\0'){

		char start = *input;
		int count = 0;

		while(*input == start){

			count++;
			input++;

		}

		int written = sprintf(output, "%c%d", start, count);

		output += written;

	}

	*output = '\0';

}