#include "Red_Black_Tree.h"

#include <iostream>
#include <cstdlib>
#include <stack>

RedBlackTree::Node::Node(int key) : key(key), color(Color::RED), left(nullptr), right(nullptr), parent(nullptr) {
}

RedBlackTree::RedBlackTree() : root(nullptr) {
}

RedBlackTree::~RedBlackTree() {
    // traverse the tree in postorder and delete each node
    std::stack<Node*> nodes;
    Node *current = root;
    while (current != nullptr || !nodes.empty()) {
        if (current != nullptr) {
            nodes.push(current);
            current = current->left;
        } else {
            Node *node = nodes.top();
            nodes.pop();
            if (node->right != nullptr) {
                nodes.push(node->right);
                current = node->right->left;
            } else {
                delete node;
            }
        }
    }
}

RedBlackTree::Node *RedBlackTree::minimum(RedBlackTree::Node *node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

RedBlackTree::Node *RedBlackTree::maximum(RedBlackTree::Node *node) const {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

RedBlackTree::Node *RedBlackTree::successor(RedBlackTree::Node *node) const {
    if (node->right != nullptr) {
        return minimum(node->right);
    }
    Node *parent = node->parent;
    while (parent != nullptr && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

RedBlackTree::Node *RedBlackTree::predecessor(RedBlackTree::Node *node) const {
    if (node->left != nullptr) {
        return maximum(node->left);
    }
    Node *parent = node->parent;
    while (parent != nullptr && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

void RedBlackTree::rotateLeft(RedBlackTree::Node *node) {
    Node *right = node->right;
    node->right = right->left;
    if (right->left != nullptr) {
        right->left->parent = node;
    }
    right->left = node;
    right->parent = node->parent;
    node->parent = right;
    if (right->parent != nullptr) {
        if (right->parent->left == node) {
            right->parent->left = right;
        } else {
            right->parent->right = right;
        }
    } else {
        root = right;
    }
}

void RedBlackTree::rotateRight(RedBlackTree::Node *node) {
    Node *left = node->left;
    node->left = left->right;
    if (left->right != nullptr) {
        left->right->parent = node;
    }
    left->right = node;
    left->parent = node->parent;
    node->parent = left;
    if (left->parent != nullptr) {
        if (left->parent->left == node) {
            left->parent->left = left;
        } else {
            left->parent->right = left;
        }
    } else {
        root = left;
    }
}

void RedBlackTree::fixUp(RedBlackTree::Node *node) {
    while (node->parent != nullptr && node->parent->color == Color::RED) {
        Node *parent = node->parent;
        Node *grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;
            if (uncle != nullptr && uncle->color == Color::RED) {
                parent->color = Color::BLACK;
                uncle->color = Color::BLACK;
                grandparent->color = Color::RED;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    node = parent;
                    rotateLeft(node);
                    parent = node->parent;
                    grandparent = parent->parent;
                }
                parent->color = Color::BLACK;
                grandparent->color = Color::RED;
                rotateRight(grandparent);
            }
        } else {
            Node *uncle = grandparent->left;
            if (uncle != nullptr && uncle->color == Color::RED) {
                parent->color = Color::BLACK;
                uncle->color = Color::BLACK;
                grandparent->color = Color::RED;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    node = parent;
                    rotateRight(node);
                    parent = node->parent;
                    grandparent = parent->parent;
                }
                parent->color = Color::BLACK;
                grandparent->color = Color::RED;
                rotateLeft(grandparent);
            }
        }
    }
    root->color = Color::BLACK;
}

void RedBlackTree::insert(int key) {
    Node *node = new Node(key);
    Node *parent = nullptr;
    Node *current = root;
    while (current != nullptr) {
        parent = current;
        if (node->key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    node->parent = parent;
    if (parent == nullptr) {
        root = node;
    } else if (node->key < parent->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    fixUp(node);
}

void RedBlackTree::remove(int key) {
    Node *node = root;
    while (node != nullptr && node->key != key) {
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    if (node == nullptr) {
        std::cout << "Value " << key << " not found";
        return;
    }

    Node *replacement = nullptr;
    if (node->left == nullptr || node->right == nullptr) {
        replacement = node;
    } else {
        replacement = successor(node);
    }

    Node *child = nullptr;
    if (replacement->left != nullptr) {
        child = replacement->left;
    } else {
        child = replacement->right;
    }

    if (child != nullptr) {
        child->parent = replacement->parent;
    }

    if (replacement->parent == nullptr) {
        root = child;
    } else if (replacement == replacement->parent->left) {
        replacement->parent->left = child;
    } else {
        replacement->parent->right = child;
    }

    if (replacement != node) {
        node->key = replacement->key;
    }

    if (replacement->color == Color::BLACK) {
        fixUp(child);
    }

    delete replacement;
}

bool RedBlackTree::search(int key) const {
    Node *node = root;
    while (node != nullptr) {
        if (key == node->key) {
            return true;
        } else if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return false;
}

