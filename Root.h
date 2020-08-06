#ifndef SUDOKU_ROOT_H
#define SUDOKU_ROOT_H


#include "Column.h"


class Root {
public:
    Column* left;
    Column* right;

    Root();
};


#endif //SUDOKU_ROOT_H
