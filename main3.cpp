
#include <iostream>
#include <ctime>

#define ROWS 30
#define COLUMNS 100

int array1[ROWS * COLUMNS];
int array2[ROWS * COLUMNS];

int total_neighbours_of(int i) {
    int total = 0;
    bool left_edge = false;
    bool right_edge = false;
    bool top_edge = false;
    bool bottom_edge = false;

    //right edge
    if ((i + 1) % COLUMNS == 0) right_edge = true;
    //left edge
    if ((i + 1) % COLUMNS == 1) left_edge = true;
    //top edge
    if (i < COLUMNS) top_edge = true;
    //bottom edge
    if (i >= COLUMNS * ROWS - COLUMNS) bottom_edge = true;

    //NW neighbour
    if (!top_edge && !left_edge) total += array1[i - COLUMNS - 1];
    //N neighbour
    if (!top_edge) total += array1[i - COLUMNS];
    //NE neighbour
    if (!top_edge && !right_edge) total += array1[i - COLUMNS + 1];
    //W neighbour
    if (!left_edge) total += array1[i - 1];
    //E neighbour
    if (!right_edge) total += array1[i + 1];
    //SW neighbour
    if (!right_edge && !bottom_edge) total += array1[i + COLUMNS - 1];
    //S neighbour
    if (!bottom_edge) total += array1[i + COLUMNS];
    //SE neighbour
    if (!bottom_edge && !right_edge) total += array1[i + COLUMNS + 1];

    //return total
    return total;
}

int main() {

    //set array1 values to 1 or 0 randomly
    int seed = time(0);
    srand(seed);
    for (int i = 0; i < ROWS * COLUMNS; i++) {
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

            if (array1[i] == 1) std::cout << "#";
            else std::cout << "_";

            if ((i + 1) % COLUMNS == 0) std::cout << std::endl;
        }

        system("cls");
        //set array1 to array2
        for (int i = 0; i < ROWS * COLUMNS; i++) {
            array1[i] = array2[i];
        }
    }
}