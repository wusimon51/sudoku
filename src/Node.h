#ifndef SUDOKU_NODE_H
#define SUDOKU_NODE_H


class Node {
public:
    Node* left = nullptr;
    Node* right = nullptr;
    Node* up = nullptr;
    Node* down = nullptr;
    int row = 0;

    void addLeft(Node* node);
    void addRight(Node* node);
    void addUp(Node* node);
    void addDown(Node* node);
    virtual void addHeader() {};
};


#endif //SUDOKU_NODE_H
