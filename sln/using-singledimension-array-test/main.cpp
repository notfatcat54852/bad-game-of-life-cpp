
#include <iostream>
#include <ctime>

#define ROWS 7
#define COLUMNS 8

int array1[ROWS * COLUMNS] = {9};
int array2[ROWS * COLUMNS];

int total_neighbours_of(int i) {
    int total = 0;
    bool left_edge = false;
    bool right_edge = false;
    bool top_edge = false;
    bool bottom_edge = false;

    //if ((i + 1) % COLUMNS == 0) std::cout << "#"; //right edge
    //else if ((i + 1) % COLUMNS == 1) std::cout << "#"; //left edge
    //else if (i < COLUMNS) std::cout << "#"; //top edge
    //else if (i >= COLUMNS * ROWS - COLUMNS) std::cout << "#"; //bottom edge

    //if (position <= ROWS) first_row = true;
    //if (position%) first_col = true;
    //if (position == ROWS - 1) last_row = true;
    //if (position == COLUMNS - 1) last_col = true;
    if ((i + 1) % COLUMNS == 0) right_edge = true; //right edge
    if ((i + 1) % COLUMNS == 1) left_edge = true; //left edge
    if (i < COLUMNS) top_edge = true; //top edge
    if (i >= COLUMNS * ROWS - COLUMNS) bottom_edge = true; //bottom edge

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

    //create random array of numbers 1 or 0
    int seed = time(0);
    srand(seed);
    for (int i = 0; i < ROWS * COLUMNS; i++) {
        array1[i] = rand() % 2;
    }

    //while (1) {
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

        ////set array values to i
        //for (int i = 0; i < ROWS * COLUMNS; i++) {
        //    array1[i] = i;
        //}

        //set single random element to 3 tell me its number of neighbours;
        int x1 = rand() % (ROWS * COLUMNS);
        array1[x1] = 3;
        std::cout << total_neighbours_of(x1) << std::endl;

        ////set borders to 1
        //for (int i = 0; i < COLUMNS * ROWS; i++) {
        //    if ((i + 1) % COLUMNS == 0) array1[i] = 1;
        //    if ((i + 1) % COLUMNS == 1) array1[i] = 1;
        //    if (i < COLUMNS) array1[i] = 1;
        //    if(i >= COLUMNS * ROWS - COLUMNS) array1[i] = 1;
        //}

        //print column number
        std::cout << " ";
        for (int i = 0; i < COLUMNS; i++) std::cout << i;
        std::cout << std::endl;

        //print array1
        for (int i = 0; i < ROWS * COLUMNS; i++) {
            //print row number
            if (i % COLUMNS == 0) std::cout << i / COLUMNS;


            if (array1[i] == 1) std::cout << "#";
            else if (array1[i] == 3) std::cout << "@";
            else std::cout << "_";

            ////testing //draws a cross
            //if (i == 9 || i == 9 - COLUMNS || i == 9 + COLUMNS || i == 9 + 1 || i == 9 - 1) std::cout << "#"; else std::cout << "_";

            ////how to get right, left, top and bottom edges //prints # border
            //if ((i + 1) % COLUMNS == 0) std::cout << "#"; //right edge
            //else if ((i + 1) % COLUMNS == 1) std::cout << "#"; //left edge
            //else if (i < COLUMNS) std::cout << "#"; //top edge
            //else if (i >= COLUMNS * ROWS - COLUMNS) std::cout << "#"; //bottom edge
            //else std::cout << "_";


            if ((i + 1) % COLUMNS == 0) std::cout << std::endl;
        }


        //std::cout << array1[COLUMNS * ROWS - 1] << std::endl;
        //std::cout << array1[44];
        //Sleep(10000);
        //system("cls");
        //set array1 to array2
        for (int i = 0; i < ROWS; i++) {
            array1[i] = array2[i];
        }
    //}
}