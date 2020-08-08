#ifndef SUDOKU_COLUMN_H
#define SUDOKU_COLUMN_H


#include <string>

#include "Node.h"


class Column {
public:
    int size;
    std::string name;
    void* left;
    void* right;
    void* up;
    void* down;
    Column* header;

    Column(int size, std::string name);
};


#endif //SUDOKU_COLUMN_H
