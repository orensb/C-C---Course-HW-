#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GRID_SIZE 3
#define TREASURE_COUNT 6
#define MIN_TREASURE_COUNT 5
#define MAX_MOVES 10
int treasuresFound = 0;
void inital_board(char board[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '_';
        }
    }
    int t = 0;
    while (t < TREASURE_COUNT) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        if (board[row][col] != 'T') {
            board[row][col] = 'T';
            t++;
        }
    }
}

int main() {
    srand(2024); // seed i3 like a "memory" when i will use a random command, the seed value insure that the next run it will be the same
    char board[GRID_SIZE][GRID_SIZE];
    int p_row,p_col,T_row,T_col,flag=0;
    inital_board(board);
    p_row = rand() % GRID_SIZE;
    p_col = rand() % GRID_SIZE;
    if (board[p_row][p_col] == 'T'){
        T_row = p_row;
        T_col = p_col;
        flag=1;
        board[p_row][p_col] = 'P';
    }
    else
        board[p_row][p_col] = 'P';
    int moves = 0;
    while (moves < MAX_MOVES && treasuresFound <TREASURE_COUNT) {
        printf("treasures Found= %d\n", treasuresFound);
        for (int i = 0; i < 3; i++) { // print the board
            for (int j = 0; j < 3; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("Moves play =%d\n",moves);
        char turn;
        printf("Enter move (D/L/U/R): ");
        scanf(" %c", &turn);
        switch (turn) {
            case 'D':
                if ((p_row + 1) < 3) {
                    if (board[p_row+1][p_col]=='T')
                        treasuresFound++;
                    board[p_row][p_col] = '_';
                    p_row = p_row + 1;
                }
                break;
            case 'U':
                if ((p_row - 1) >= 0) {
                    if (board[p_row-1][p_col]=='T')
                        treasuresFound++;
                    board[p_row][p_col] = '_';
                    p_row = p_row - 1;
                }
                break;
            case 'L':
                if ((p_col - 1) >= 0) {
                    if (board[p_row][p_col-1]=='T')
                        treasuresFound++;
                    board[p_row][p_col] = '_';
                    p_col = p_col - 1;
                }
                break;
            case 'R':
                if ((p_col + 1) < 3){
                    if (board[p_row][p_col+1]=='T')
                        treasuresFound++;
                    board[p_row][p_col] = '_';
                    p_col = p_col + 1;
        }
                break;
            default:
                    printf("Wrong choice, need capital letter (D/L/U/R)\n");
                continue;
        }
        moves++;
        board[p_row][p_col] ='P';
        if (moves==1 && flag==1)
            board[T_row][T_col] = 'T';
    }

    for (int i = 0; i < 3; i++) { // print the board
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    if (treasuresFound >= TREASURE_COUNT)
        printf("\nCongratulations! You found all the treasures in %d.\n",moves);
    else
        printf("\nSorry, you ran out of moves %d.\n",moves);
    return 0;
}

