#include "Node.h"


Node::Node(int value, Node* left, Node* right) {
    this->value = value;
    this->left = left;
    this->right = right;
}