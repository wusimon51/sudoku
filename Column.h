#ifndef SUDOKU_COLUMN_H
#define SUDOKU_COLUMN_H


#include "Node.h"


class Column : public Node {
public:
    int size;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::unique_ptr<Node> up;
    std::unique_ptr<Node> down;
    std::unique_ptr<Column> header;

    Column(int size);
};


#endif //SUDOKU_COLUMN_H
