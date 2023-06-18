
#include <iostream>
#include <ctime>

#define ROWS 30
#define COLUMNS 100

int array1[ROWS * COLUMNS];
int array2[ROWS * COLUMNS];

int total_neighbours_of(int position) {
    int total = 0;
    bool first_col = false;
    bool first_row = false;
    bool last_col = false;
    bool last_row = false;

    if (position <= ROWS) first_row = true;
    if (position % ) first_col = true;
    if (position == ROWS - 1) last_row = true;
    if (position == COLUMNS - 1) last_col = true;


    //NW neighbour
    if (!first_row && !first_col) total += array1[row - 1];
    //N neighbour
    if (!first_row) total += array1[row - 1];
    //NE neighbour
    if (!first_row && !last_col) total += array1[row - 1];
    //W neighbour
    if (!first_col) total += array1[row];
    //E neighbour
    if (!last_col) total += array1[row];
    //SW neighbour
    if (!first_col && !last_row) total += array1[row + 1];
    //S neighbour
    if (!last_row) total += array1[row + 1];
    //SE neighbour
    if (!last_row && !last_col) total += array1[row + 1];



    return total;
}

int main() {
    //create random array of numbers 1 or 0
    int seed = time(0);
    srand(seed);
    for (int i = 0; i < ROWS; i++) {
        array1[i] = rand() % 2;
    }
    while (1) {
        //apply rules of life
        for (int i = 0; i < ROWS * COLUMNS; i++) {
                int neighbours = total_neighbours_of(i);
                if (array1[i] == 1 && (neighbours == 2 || neighbours == 3)) {
                    array2[i] = 1;
                }
                else if (array1[i] == 0 && neighbours == 3) {
                    array2[i] = 1;
                }
                else {
                    array2[i] = 0;
                }
        }
        //print array1
        for (int i = 0; i < ROWS * COLUMNS; i++) {
            if (array1[i]) std::cout << "#"; else std::cout << "_";
            std::cout << std::endl;
        }
        //Sleep(10000);
        system("cls");
        //set array1 to array2
        for (int i = 0; i < ROWS; i++) {
            array1[i] = array2[i];
        }
    }
}