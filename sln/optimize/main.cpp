
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#define ROWS 30
#define COLUMNS 100

int array1[ROWS][COLUMNS];
int array2[ROWS][COLUMNS];

int total_neighbours_of(int row, int col) {
    int total = 0;
    bool first_col = false;
    bool first_row = false;
    bool last_col = false;
    bool last_row = false;

    if (col == 0) first_col = true;
    if (row == 0) first_row = true;
    if (col == COLUMNS - 1) last_col = true;
    if (row == ROWS - 1) last_row = true;


    //NW neighbour
    if (!first_row && !first_col) total += array1[row - 1][col - 1];
    //N neighbour
    if (!first_row) total += array1[row - 1][col];
    //NE neighbour
    if (!first_row && !last_col) total += array1[row - 1][col + 1];
    //W neighbour
    if (!first_col) total += array1[row][col - 1];
    //E neighbour
    if (!last_col) total += array1[row][col + 1];
    //SW neighbour
    if (!first_col && !last_row) total += array1[row + 1][col - 1];
    //S neighbour
    if (!last_row) total += array1[row + 1][col];
    //SE neighbour
    if (!last_row && !last_col) total += array1[row + 1][col + 1];



    return total;
}

int main() {
    //create random array of numbers 1 or 0
    int seed = time(0);
    srand(seed);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            array1[i][j] = rand() % 2;
        }
        //std::cout << std::endl;
    }
    while (1) {
        //apply rules of life
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                int neighbours = total_neighbours_of(i, j);
                if (array1[i][j] == 1 && (neighbours == 2 || neighbours == 3)) {
                    array2[i][j] = 1;
                }
                else if (array1[i][j] == 0 && neighbours == 3) {
                    array2[i][j] = 1;
                }
                else {
                    array2[i][j] = 0;
                }
            }
        }
        //print array1
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (array1[i][j]) //std::cout << "#"; else std::cout << "_";
                    printf("#"); else printf("#");
            }
            //std::cout << std::endl;
            printf("\n");
        }
        //Sleep(10000);
        //system("cls");
        //set array1 to array2
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                array1[i][j] = array2[i][j];
            }
        }
    }
}