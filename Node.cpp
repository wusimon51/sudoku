#include "Node.h"


Node::Node(int value) {
    this->value = value;
}

void Node::addLeft(Node *node) {
    this->left = node;
}

void Node::addRight(Node *node) {
    this->right = node;
}