#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[20];
    char surname[20];
    char fullname[40];

    printf("\n=== First Name + Last Name ===\n\n");

    printf("Enter your name: ");

    if(scanf("%19s", name) != 1){

        fprintf(stderr, "[ERROR] Failed to read name.\n");
        return 1;

    }

    printf("Enter your surname: ");

    if(scanf("%19s", surname) != 1){

        fprintf(stderr, "[ERROR] Failed to read surname.\n");
        return 1;

    }

    fullname[0] = '\0';

    strcat(fullname, name);
    strcat(fullname, " ");
    strcat(fullname, surname);

    printf("\n[SUCCESS] Your full name: '%s'\n", fullname);

    return 0;
}