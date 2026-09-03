#include <stdio.h>


enum MediaType {

	BOOK,
	MAGAZINE,
	DVD

};


union MediaInfo{

	int pages;
	int issue_number;
	int duration_min;

};


struct LibraryItem{

	char title[50];
	enum MediaType type;
	union MediaInfo info;
	float price;

};


int read_items(struct LibraryItem *item, int n);
void print_item(struct LibraryItem item);
float total_price(struct LibraryItem *items, int n);
int find_cheapest(struct LibraryItem *items, int n);


int main()
{

	printf("\n\nLibrary\n\n");

	printf("\nInputing information\n");

	int n = 4;
	struct LibraryItem items[n];

	if(read_items(items, n) != 0){

		return 1;

	}


	printf("\n------ -----\n");

	for(int i = 0; i < n; i++){

		print_item(items[i]);

	}


	printf("\n------ ------\n");

	float tot_result = total_price(items, n);

	printf("\nTotal: %.2f\n", tot_result);


	int cheapest_index = find_cheapest(items, n);

	printf("\n--Cheapest--\n");

	print_item(items[cheapest_index]);


	return 0;
}



int read_items(struct LibraryItem *item, int n)
{

	for(int i = 0; i < n; i++){

		int type_choice = 0;

		printf("\nEnter type of object 0-BOOK, 1-MAGAZINE, 2-DVD: ");

		if(scanf("%d", &type_choice) != 1){

			printf("[ERROR] Invalid media type!\n");
			return 1;

		}


		if(type_choice < BOOK || type_choice > DVD){

			printf("[ERROR] Unknown media type!\n");
			return 1;

		}


		item[i].type = (enum MediaType)type_choice;


		switch(item[i].type){

			case BOOK:

				printf("\nEnter title of book: ");

				if(scanf("%49s", item[i].title) != 1){

					printf("[ERROR] Failed to read book title!\n");
					return 1;

				}


				printf("\nEnter pages of book: ");

				if(scanf("%d", &item[i].info.pages) != 1){

					printf("[ERROR] Invalid pages!\n");
					return 1;

				}


				printf("\nEnter price of book: ");

				if(scanf("%f", &item[i].price) != 1){

					printf("[ERROR] Invalid price!\n");
					return 1;

				}

				break;


			case MAGAZINE:

				printf("\nEnter title of magazine: ");

				if(scanf("%49s", item[i].title) != 1){

					printf("[ERROR] Failed to read magazine title!\n");
					return 1;

				}


				printf("\nEnter issue number: ");

				if(scanf("%d", &item[i].info.issue_number) != 1){

					printf("[ERROR] Invalid issue number!\n");
					return 1;

				}


				printf("\nEnter price of magazine: ");

				if(scanf("%f", &item[i].price) != 1){

					printf("[ERROR] Invalid price!\n");
					return 1;

				}

				break;


			case DVD:

				printf("\nEnter title of film: ");

				if(scanf("%49s", item[i].title) != 1){

					printf("[ERROR] Failed to read film title!\n");
					return 1;

				}


				printf("\nEnter duration of film min: ");

				if(scanf("%d", &item[i].info.duration_min) != 1){

					printf("[ERROR] Invalid duration!\n");
					return 1;

				}


				printf("\nEnter price of film: ");

				if(scanf("%f", &item[i].price) != 1){

					printf("[ERROR] Invalid price!\n");
					return 1;

				}

				break;

		}

	}


	return 0;

}


void print_item(struct LibraryItem item)
{

	switch(item.type){

		case BOOK:

			printf("\nName: %s\n", item.title);
			printf("Pages: %d\n", item.info.pages);
			printf("Price: %.2f\n", item.price);

			break;


		case MAGAZINE:

			printf("\nName: %s\n", item.title);
			printf("Issue number: %d\n", item.info.issue_number);
			printf("Price: %.2f\n", item.price);

			break;


		case DVD:

			printf("\nName: %s\n", item.title);
			printf("Duration: %d\n", item.info.duration_min);
			printf("Price: %.2f\n", item.price);

			break;

	}

}


float total_price(struct LibraryItem *items, int n)
{

	float total = 0.0f;

	for(int i = 0; i < n; i++){

		total += items[i].price;

	}

	return total;
}


int find_cheapest(struct LibraryItem *items, int n)
{

	int cheapest = 0;

	for(int i = 1; i < n; i++){

		if(items[cheapest].price > items[i].price){

			cheapest = i;

		}

	}

	return cheapest;
}
