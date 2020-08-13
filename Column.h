#ifndef SUDOKU_COLUMN_H
#define SUDOKU_COLUMN_H


#include <string>

#include "Node.h"


class Column : public Node {
public:
    int size;
    std::string name;

    Column(int size, std::string name);
};


#endif //SUDOKU_COLUMN_H
