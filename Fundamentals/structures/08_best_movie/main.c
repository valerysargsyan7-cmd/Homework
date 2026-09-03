#include <stdio.h>

struct Movie {

	char title[50];
	unsigned int ratings[5];
	int average;

};

int film_info_input(struct Movie movies[], int movies_quantity);
int highest_rating_film(struct Movie movies[], int movies_quantity);
void film_info_output(struct Movie movie);

int main()
{
	printf("\n\nBest film\n\n");

	int movies_quantity = 5;

	struct Movie movies[5];


	printf("Info input\n");

	if(film_info_input(movies, movies_quantity) != 0){

		return 1;

	}


	int best_film_index = highest_rating_film(
		movies,
		movies_quantity
	);


	if(best_film_index == -1){

		fprintf(stderr, "[ERROR] Failed to find best movie.\n");
		return 1;

	}


	film_info_output(movies[best_film_index]);


	return 0;
}




int film_info_input(struct Movie movies[], int movies_quantity)
{
	for(int i = 0; i < movies_quantity; i++){

		printf("\nEnter %dth movie title: ", i + 1);

		if(scanf("%49s", movies[i].title) != 1){

			fprintf(stderr, "[ERROR] Failed to read movie title.\n");
			return 1;

		}


		for(int j = 0; j < 5; j++){

			printf("Enter %dth rating for %dth movie: ",
			       j + 1,
			       i + 1);

			if(scanf("%u", &movies[i].ratings[j]) != 1){

				fprintf(stderr,
				        "[ERROR] Invalid rating for movie %d.\n",
				        i + 1);
				return 1;

			}


			if(movies[i].ratings[j] > 10){

				fprintf(stderr,
				        "[ERROR] Rating must be between 0 and 10.\n");
				return 1;

			}
		}
	}

	return 0;
}


int highest_rating_film(struct Movie movies[], int movies_quantity)
{
	if(movies == NULL || movies_quantity <= 0){

		return -1;

	}


	int max_rating = 0;


	for(int i = 0; i < movies_quantity; i++){

		unsigned int sum_rating = 0;


		for(int j = 0; j < 5; j++){

			sum_rating += movies[i].ratings[j];

		}


		movies[i].average = (int)(sum_rating / 5);


		if(movies[i].average > movies[max_rating].average){

			max_rating = i;

		}

	}


	return max_rating;
}


void film_info_output(struct Movie movie)
{
	printf("\n\nBest movie\n\n");

	printf("Movie title: %s\n", movie.title);


	for(int i = 0; i < 5; i++){

		printf("%dth Rating: %u\n",
		       i + 1,
		       movie.ratings[i]);

	}


	printf("Average: %d\n", movie.average);
}
