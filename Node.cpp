#include "Node.h"


void Node::addLeft(Node* node) {
    this->left = static_cast<std::unique_ptr<Node>>(node);
}

void Node::addRight(Node* node) {
    this->right = static_cast<std::unique_ptr<Node>>(node);
}

void Node::addUp(Node *node) {
    this->up = static_cast<std::unique_ptr<Node>>(node);
}

void Node::addDown(Node *node) {
    this->down = static_cast<std::unique_ptr<Node>>(node);
}