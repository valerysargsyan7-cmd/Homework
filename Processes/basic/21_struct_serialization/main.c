#include <stdio.h>
#include <stdlib.h>

struct Product {
	int id;
	int size;
	float price;
};

void save_products(const char *file, const struct Product *arr, int size);
void load_products(const char *file);

int main()
{

	printf("\n\nBinary Struct Serialization & Deserialization\n\n");

	const char *products_file = "Products.bin";

	int count = 3;
	struct Product products[3];

	printf("Enter information for %d products:\n", count);

	for(int i = 0; i < count; i++){

		printf("\nProduct %d ID: ", i + 1);
		if(scanf("%d", &products[i].id) != 1){

			fprintf(stderr, "[ERROR] Invalid ID input.\n");
			return 1;

		}

		printf("Product %d Size: ", i + 1);
		if(scanf("%d", &products[i].size) != 1){

			fprintf(stderr, "[ERROR] Invalid Size input.\n");
			return 1;

		}

		if(products[i].size > 10){

			printf("[WARNING] Size exceeds standard threshold (> 10).\n");

		}

		printf("Product %d Price: ", i + 1);
		if(scanf("%f", &products[i].price) != 1){

			fprintf(stderr, "[ERROR] Invalid Price input.\n");
			return 1;

		}

	}

	save_products(products_file, products, count);

	printf("\n--- Reading Saved Products from Binary File ---\n");
	load_products(products_file);

	printf("\nWork status: DONE\n");

	return 0;

}

void save_products(const char *file, const struct Product *arr, int size)
{

	FILE *fp_prod_save = fopen(file, "wb");

	if(fp_prod_save == NULL){

		perror("[ERROR] File opening error in save_products");
		return;

	}

	size_t written = fwrite(arr, sizeof(struct Product), (size_t)size, fp_prod_save);

	if(written != (size_t)size){

		perror("[ERROR] Failed to write all product records");

	}else{

		printf("\nInfo saving status: DONE (%zu records written)\n", written);

	}

	fclose(fp_prod_save);

}

void load_products(const char *file)
{

	FILE *fp_prod_load = fopen(file, "rb");

	if(fp_prod_load == NULL){

		perror("[ERROR] File opening error in load_products");
		return;

	}

	struct Product read_prod;

	while(fread(&read_prod, sizeof(struct Product), 1, fp_prod_load) == 1){

		printf("ID: %d | Price: %.2f | Size: %d\n", read_prod.id, read_prod.price, read_prod.size);

	}

	fclose(fp_prod_load);

}
