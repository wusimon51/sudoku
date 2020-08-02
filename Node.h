#ifndef SUDOKU_NODE_H
#define SUDOKU_NODE_H


class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left, Node* right);
};


#endif //SUDOKU_NODE_H
