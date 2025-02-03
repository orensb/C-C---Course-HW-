#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // For sleep function
// Define a structure for the smart home state
typedef struct {
    bool lamp1; //for each lamp
    bool lamp2;
    bool lamp3;
    int dimmerALevel; // 0 to 4
    int dimmerBLevel; // 0 to 4
    int temperatureRoomLevel; // 0 to 9
} SmartHomeState; // in SmartHomeState we have 6 variables
// Function prototypes
void initializeSmartHome(SmartHomeState *state){ //just creating the a general srucutre
    state->lamp1 = false;
    state->lamp2 = false;
    state->lamp3 = false;
    state->dimmerALevel = 0;
    state->dimmerBLevel = 0;
    state->temperatureRoomLevel = 0;
}
void updateLighting(SmartHomeState *state, bool lamp1, bool lamp2, bool lamp3, int dimmerA, int dimmerB){
    state->lamp1 = lamp1;
    state->lamp2 = lamp2;
    state->lamp3 = lamp3;
    state->dimmerALevel = dimmerA;
    state->dimmerBLevel = dimmerB;
}

void updateTemperature(SmartHomeState *state, int temperature){
    state->temperatureRoomLevel = temperature;
}

void printSmartHomeState(const SmartHomeState *state){
    printf("Room State:\n");
    printf("Lamps: 1[%s]",
           state->lamp1 ? "ON" : "OFF");
    printf("Lamps: 2[%s]",
           state->lamp2 ? "ON" : "OFF");
    printf("Lamps: 3[%s]\n",
           state->lamp3 ? "ON" : "OFF");

    printf("Dimmer Levels: A[%d] B[%d]\n", state->dimmerALevel, state->dimmerBLevel);
    printf("Temperature: %d°C\n", state->temperatureRoomLevel);
}

void drawRoom(const SmartHomeState *state){
    //first need to draw lamps and then temp'
    {
        if (state->lamp1)
            for (int j = 0; j < state->dimmerALevel+1; j++)
                printf("*");
        else
            printf("-");
    }
    printf("\n");
    {
        if (state->lamp2)
            for (int j = 0; j < state->dimmerALevel+1; j++)
                printf("*");
        else
            printf("-");
    }
    printf("\n");
    {
        if (state->lamp3)
            for (int j = 0; j < state->dimmerBLevel+1; j++)
                printf("*");
        else
            printf("-");
    }
    printf("\n");
    printf("Temperature: ");
    for (int i = 0; i < state->temperatureRoomLevel + 1; i++) {
        printf("-");
    }
    printf("\n");

}

bool isValidInput(char d) {
    return d>= '1' && d<='5';
}

void getSimCode(int arr[]){
    char input[5];
    int flag=1;
    while (flag){
        printf("Simulation senario code: Enter Five digits without spaces (1-5): ");
        scanf(" %c%c%c%c%c", &input[0], &input[1],  &input[2],  &input[3],  &input[4]);
        while (getchar() != '\n');

        if (isValidInput(input[0]) && isValidInput(input[1]) && isValidInput(input[2])&& isValidInput(input[3])&& isValidInput(input[4])
        )
        {
            break; // Break the loop if all inputs are valid
        } else {
            printf("Invalid input. Please enter digits from 1 to 5 only.\n");
        }
    }
    arr[0]=input[0]-'0';
    arr[1]=input[1]-'0';
    arr[2]=input[2]-'0';
    arr[3]=input[3]-'0';
    arr[4]=input[4]-'0';

    printf("You entered: %d, %d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3] ,arr[4]);
    }


int main() {
    SmartHomeState state;
    int i, simcode[5];
    getSimCode(simcode);//It convert from char digits into integer digits
    initializeSmartHome(&state);
// Simulate different situations
    for (i = 0; i < 5; i++) {
//update new home state base on the given code (e.g 24553)
        updateLighting(&state, i % simcode[0] == 0, i % simcode[1] == 0, i % simcode[2] == 0, i % simcode[3], (4 - i) % simcode[4]);
        updateTemperature(&state, i);
        printSmartHomeState(&state);
        drawRoom(&state);
        sleep(1); // sleep for 1 second
    }
    return 0;
}