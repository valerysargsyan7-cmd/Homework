#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

struct User {
	int id;
	char name[20];
	int age;
};

struct User *load_database(const char *filename, int max_users);

int main()
{

	printf("\n\nPersistent Struct Database via Mmap\n\n");

	const char *db_filename = "user_database.dat";
	int max_users = 5;

	struct User *db = load_database(db_filename, max_users);

	if(db == NULL){

		fprintf(stderr, "[ERROR] Failed to load database.\n");
		return 1;

	}

	int choice = 0;

	while(1){

		printf("\n--- Database Menu ---\n");
		printf("1. Add user record\n");
		printf("2. Show all user records\n");
		printf("3. Exit\n");
		printf("Select option: ");

		if(scanf("%d", &choice) != 1){

			break;

		}

		if(choice == 1){

			int added = 0;
			for(int i = 0; i < max_users; i++){

				if(db[i].id == 0){

					printf("Enter User ID: ");
					if(scanf("%d", &db[i].id) != 1){
						db[i].id = 1;
					}

					printf("Enter Username: ");
					if(scanf("%19s", db[i].name) != 1){
						strncpy(db[i].name, "User", 20);
					}

					printf("Enter Age: ");
					if(scanf("%d", &db[i].age) != 1){
						db[i].age = 20;
					}

					printf("[SUCCESS] User saved at slot %d directly to mapped file.\n", i);
					added = 1;
					break;

				}

			}

			if(!added){

				printf("[INFO] Database is full (%d records max).\n", max_users);

			}

		}else if(choice == 2){

			printf("\n--- Active Records in Database ---\n");
			int found = 0;

			for(int i = 0; i < max_users; i++){

				if(db[i].id != 0){

					printf("Slot [%d]: ID=%-4d | Name=%-15s | Age=%d\n",
					       i, db[i].id, db[i].name, db[i].age);
					found++;

				}

			}

			if(found == 0){

				printf("No records found (Database is empty).\n");

			}

		}else if(choice == 3){

			printf("\nUnmapping and saving database to disk. Goodbye!\n");
			break;

		}else{

			printf("[WARNING] Invalid option selected.\n");

		}

	}

	munmap(db, (size_t)max_users * sizeof(struct User));
	return 0;

}

struct User *load_database(const char *filename, int max_users)
{

	int fd = open(filename, O_CREAT | O_RDWR, 0644);

	if(fd < 0){

		perror("[ERROR] Failed to open database file");
		return NULL;

	}

	size_t db_size = (size_t)max_users * sizeof(struct User);

	if(ftruncate(fd, (off_t)db_size) == -1){

		perror("[ERROR] ftruncate failed");
		close(fd);
		return NULL;

	}

	struct User *db = (struct User *)mmap(NULL, db_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	close(fd);

	if(db == MAP_FAILED){

		perror("[ERROR] mmap failed");
		return NULL;

	}

	return db;

}
