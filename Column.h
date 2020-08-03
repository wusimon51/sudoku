#ifndef SUDOKU_COLUMN_H
#define SUDOKU_COLUMN_H


#include <string>

#include "Node.h"


class Column {
public:
    Node* left;
    Node* right;
    Node* up;
    Node* down;

    int size;
    std::string name;

    Column();
};


#endif //SUDOKU_COLUMN_H
