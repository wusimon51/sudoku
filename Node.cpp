#include "Node.h"


Node::Node(int value, Node* header) {
    this->value = value;
    this->header = header;
}

void Node::addLeft(Node*& node) {
    this->left = node;
}

void Node::addRight(Node* node) {
    this->right = node;
}

void Node::addUp(Node *node) {
    this->up = node;
}

void Node::addDown(Node *node) {
    this->down = node;
}