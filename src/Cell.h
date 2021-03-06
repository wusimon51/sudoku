#ifndef SUDOKU_CELL_H
#define SUDOKU_CELL_H


#include "Node.h"
#include "Column.h"


class Cell : public Node {
public:
    Column* header = nullptr; //Subclass Column will be used

    void addHeader(Column* col);
};


#endif //SUDOKU_CELL_H
