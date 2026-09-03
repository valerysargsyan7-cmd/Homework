#include <stdio.h>

union Identifier{

    int idNumber;
    char passportNumber[20];

};

enum IdType{

    ID_NUM,
    PASSPORT

};

struct Person{

    char name[20];
    enum IdType type;
    union Identifier id;

};

int main()
{
    printf("\n\nPersonal info\n\n");

    struct Person persona[3];

    for(int i = 0; i < 3; i++){

        printf("Enter your name: ");

        if(scanf("%19s", persona[i].name) != 1){

            fprintf(stderr, "[ERROR] Invalid name input.\n");
            return 1;

        }

        int type_choice = 0;

        printf("Enter your type ID_NUM - 0, PASSPORT - 1: ");

        if(scanf("%d", &type_choice) != 1){

            fprintf(stderr, "[ERROR] Invalid ID type input.\n");
            return 1;

        }

        if(type_choice < 0 || type_choice > 1){

            fprintf(stderr, "[ERROR] Invalid ID type. Please enter 0 or 1.\n");
            i--;
            continue;

        }

        persona[i].type = type_choice;

        if(persona[i].type == ID_NUM){

            printf("Enter your ID: ");

            if(scanf("%d", &persona[i].id.idNumber) != 1){

                fprintf(stderr, "[ERROR] Invalid ID input.\n");
                return 1;

            }

        }else{

            printf("Enter your passport number: ");

            if(scanf("%19s", persona[i].id.passportNumber) != 1){

                fprintf(stderr, "[ERROR] Invalid passport input.\n");
                return 1;

            }
        }
    }

    printf("\nPeople information:\n");

    for(int i = 0; i < 3; i++){

        printf("\nName: %s\n", persona[i].name);

        if(persona[i].type == ID_NUM){

            printf("ID: %d\n", persona[i].id.idNumber);

        }else{

            printf("Passport: %s\n", persona[i].id.passportNumber);

        }
    }

    return 0;
}