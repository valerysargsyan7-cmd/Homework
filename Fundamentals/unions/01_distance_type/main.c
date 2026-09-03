#include <stdio.h>

typedef enum
{
    METERS = 0,
    CENTIMETERS = 1

} DistanceTypeChoice;

struct MetersCentimeters
{
    int centimeters;
    float meters;
};

union MetersOrCentimeters
{
    struct MetersCentimeters value;
};

int main(void)
{
    DistanceTypeChoice choice;
    union MetersOrCentimeters distance;
    int choice_input = 0;

    printf("\n=== Distance Value and Type ===\n\n");

    printf(
        "Choose type of distance "
        "(0-meters, 1-centimeters): "
    );

    if(scanf("%d", &choice_input) != 1){

        fprintf(stderr, "[ERROR] Invalid distance type.\n");
        return 1;

    }

    if(choice_input < METERS || choice_input > CENTIMETERS){

        fprintf(stderr, "[ERROR] Distance type must be 0 or 1.\n");
        return 1;

    }

    choice = (DistanceTypeChoice)choice_input;

    if(choice == METERS){

        printf("Enter meters: ");

        if(scanf("%f", &distance.value.meters) != 1){

            fprintf(stderr, "[ERROR] Invalid meter value.\n");
            return 1;

        }

        if(distance.value.meters < 0.0f){

            fprintf(stderr, "[ERROR] Distance cannot be negative.\n");
            return 1;

        }

        printf(
            "\n[SUCCESS] Distance in meters: %.2f\n",
            distance.value.meters
        );

    }else{

        printf("Enter centimeters: ");

        if(scanf("%d", &distance.value.centimeters) != 1){

            fprintf(stderr, "[ERROR] Invalid centimeter value.\n");
            return 1;

        }

        if(distance.value.centimeters < 0){

            fprintf(stderr, "[ERROR] Distance cannot be negative.\n");
            return 1;

        }

        printf(
            "\n[SUCCESS] Distance in centimeters: %d\n",
            distance.value.centimeters
        );
    }

    return 0;
}