
#include <iostream>
#include <windows.h>

#define ROWS 30
#define COLUMNS 100

//int array1[ROWS][COLUMNS] = {
//    { 8, 7, 1, 0, 0, 0, 0, 0, 0, 0},//row 0
//    { 1, 9, 1, 0, 0, 0, 0, 0, 0, 0},//row 1
//    { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},//row 2
//    //0  1  2  3  4  5  6  7  8   9//columns
//};
int array1[ROWS][COLUMNS] = {
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},//row 0
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},//row 1
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},//row 2
    //0  1  2  3  4  5  6  7  8   9//columns
};
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
    ////print coordinates
    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLUMNS; j++) {
    //        std::cout << "(" << i << "," << j << ")";
    //    }
    //    std::cout << std::endl;
    //}
    ////increasing first dimension moves us down //origin top left
    //std::cout << array1[0][0] << std::endl;
    //std::cout << array1[1][0] << std::endl;
    //std::cout << array1[2][0] << std::endl;
    ////increasing second dimension moves us right //origin top left
    //std::cout << array1[0][0] << std::endl;
    //std::cout << array1[0][1] << std::endl;
    //std::cout << array1[0][2] << std::endl;
    ////returns 9
    //std::cout << array1[1][1] << std::endl;

    ////print array
    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLUMNS; j++) {
    //        std::cout << array1[i][j];
    //    }
    //    std::cout << std::endl;
    //}
    ////checking the neighbours are counted correctly
    //std::cout << total_neighbours_of(0, 1);//20
    //std::cout << std::endl;
    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLUMNS; j++) {
    //        std::cout << total_neighbours_of(i, j) << " ";
    //    }
    //    std::cout << std::endl;
    //}

    //create random array of numbers 1 or 0
    int seed = time(0);
    srand(seed);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            array1[i][j] = rand()%2;
        }
        std::cout << std::endl;
    }
    //create cycle counter limit
    int cycles = 0;
    while (cycles < 1000) {
        ////print seed
        //std::cout << std::endl << seed << std::endl;
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
                if (array1[i][j]) std::cout << "#"; else std::cout << "_";
            }
            std::cout << std::endl;
        }
        Sleep(100);
        system("cls");
        //set array1 to array2
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                array1[i][j] = array2[i][j];
            }
        }
        cycles++;
    }
}

//#include <iostream>
//
//#define COLUMNS 10
//#define ROWS 3
//
//int array1[ROWS][COLUMNS] = {
//    { 1, 1, 1, 0, 0, 0, 0, 0, 0 },
//    { 1, 9, 1, 0, 0, 0, 0, 0, 0 },
//    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//};
//
//int main() {
//
//    for (int i = 0; i < ROWS; i++) {
//        for (int j = 0; j < COLUMNS; j++) {
//            std::cout << "(" << i << "," << j << " = " << array1[i][j] << ")";
//        }
//        std::cout << std::endl;
//    }
//    //increasing first dimension moves us down //origin top left
//    std::cout << array1[0][0] << std::endl;
//    std::cout << array1[1][0] << std::endl;
//    std::cout << array1[2][0] << std::endl;
//    //increasing second dimension moves us right //origin top left
//    std::cout << array1[0][0] << std::endl;
//    std::cout << array1[0][1] << std::endl;
//    std::cout << array1[0][2] << std::endl;
//    //returns 9
//    std::cout << array1[1][1] << std::endl;
//}

//#include <iostream>
//
//#define COLUMNS 10
//#define ROWS 3
//
//int array1[ROWS][COLUMNS] = {
//    { 1, 1, 1, 0, 0, 0, 0, 0, 0 },
//    { 1, 9, 1, 0, 0, 0, 0, 0, 0 },
//    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//};
//
//int main() {
//
//    for (int i = 0; i < ROWS; i++) {
//        for (int j = 0; j < COLUMNS; j++) {
//            std::cout << "(" << i << "," << j << ")";
//        }
//        std::cout << std::endl;
//    }
//    //increasing first dimension moves us down //origin top left
//    std::cout << array1[0][0] << std::endl;
//    std::cout << array1[1][0] << std::endl;
//    std::cout << array1[2][0] << std::endl;
//    //increasing second dimension moves us right
//    std::cout << array1[0][0] << std::endl;
//    std::cout << array1[0][1] << std::endl;
//    std::cout << array1[0][2] << std::endl;
//    //returns 9
//    std::cout << array1[1][1] << std::endl;
//}



//int array[ROWS][COLUMNS] = {};
//
//int main() {
//
//    for (int i = 0; i < ROWS; i++) {
//        for (int j = 0; j < COLUMNS; j++) {
//            std::cout << "#";
//        }
//        std::cout << std::endl;
//    }
//}