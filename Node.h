#ifndef SUDOKU_NODE_H
#define SUDOKU_NODE_H


class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value);

    void addLeft(Node* node);
    void addRight(Node* node);
};


#endif //SUDOKU_NODE_H
