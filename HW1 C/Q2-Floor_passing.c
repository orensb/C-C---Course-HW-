#include <stdio.h>
#include <string.h>
#define MAX_FLOORS 10;

void floor_change(char floorNames[][15],int *floor_change,int *current_floor) {
    if (*floor_change == *current_floor)
        printf("Arrived at Floor %s\n", floorNames[*floor_change]); // dest floor
    else if (*floor_change > *current_floor) {//elevator go up (from floor 2(current) to floor 6 (wanted)
        for (int i = (*current_floor+1); i < (*floor_change + 1); i++) {
            printf("Passing Floor %s\n", floorNames[i]); // print all the floor
        }
        printf("Arrived at Floor %s\n", floorNames[*floor_change]); // dest floor
        *current_floor = *floor_change;
    } else { //elevator go down (from floor 6(current) to floor 2 (wanted)
        for (int j = (*current_floor-1); j > (*floor_change-1); j--) {
            printf("Passing Floor %s\n", floorNames[j]); // print all the floor
        }
        printf("Arrived at Floor %s\n", floorNames[*floor_change]); // dest floor
        *current_floor = *floor_change;
    }
}



int main() {
    char floorNames[][15] = {"Zero floor", "First floor", "Second floor", "Third floor", "Fourth floor",
                             "Fifth floor", "Sixth floor", "Seventh floor", "Eighth floor",
                             "Ninth floor",
    };
    int floor_choice=0, current_floor = 0;
    char floor_choice_c;
    while (floor_choice!=-1){
        printf("Enter the floor number you wish to go to (-1 to exit): ");
        if(scanf("%d", &floor_choice)==1) {
            if (getchar()!= '\n' || floor_choice < 0 || floor_choice > 9) {
                printf("You requested to go to the Number is out of range.\n");
                printf("\nInvalid floor number.\n");
                while (getchar() != '\n');
            } else {
                printf("You requested to go to the %s\n", floorNames[floor_choice]);
                floor_change(floorNames, &floor_choice, &current_floor);
            }
        } else {
            printf("\nInvalid floor number.\n");
            while (getchar() != '\n');
        }
    }
    printf("Elevator simulation ended.");
    return 0;
}

