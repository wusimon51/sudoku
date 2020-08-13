#ifndef SUDOKU_NODE_H
#define SUDOKU_NODE_H


#include <memory>


class Node {
public:
    Node* left;
    Node* right;
    Node* up;
    Node* down;
    Node* header; //Subclass Column will be used

    void addLeft(Node* node);
    void addRight(Node* node);
    void addUp(Node* node);
    void addDown(Node* node);
    void addHeader(Node* node);
};


#endif //SUDOKU_NODE_H
