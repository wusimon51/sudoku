#ifndef SUDOKU_NODE_H
#define SUDOKU_NODE_H


#include <memory>


class Node {
public:
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::unique_ptr<Node> up;
    std::unique_ptr<Node> down;
    std::unique_ptr<Node> header; //Subclass Column will be used

    Node(int value);

    void addLeft(Node* node);
    void addRight(Node* node);
    void addUp(Node* node);
    void addDown(Node* node);
};


#endif //SUDOKU_NODE_H
