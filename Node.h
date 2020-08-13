#ifndef SUDOKU_NODE_H
#define SUDOKU_NODE_H


class Node {
public:
    Node* left;
    Node* right;
    Node* up;
    Node* down;

    void addLeft(Node* node);
    void addRight(Node* node);
    void addUp(Node* node);
    void addDown(Node* node);
};


#endif //SUDOKU_NODE_H
