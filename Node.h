#ifndef SUDOKU_NODE_H
#define SUDOKU_NODE_H


#include "Column.h"


class Node {
public:
    int value;
    void* left;
    void* right;
    void* up;
    void* down;
    Column* header;

    Node(int value, Column* header);

    void addLeft(Node* node);
    void addRight(Node* node);
    void addUp(Node* node);
    void addDown(Node* node);
};


#endif //SUDOKU_NODE_H
