#include "BST.h"
#include <iostream>
#include <iomanip>

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    freeNode(root);
}

void BST::freeNode(Node* leaf) {
    if (leaf != nullptr) {
        freeNode(leaf->left);
        freeNode(leaf->right);
        delete leaf;
    }
}

void BST::addNode(int data) {
    if (root == nullptr) {
        root = new Node;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        addNode(data, root);
    }
}

void BST::addNode(int data, Node* leaf) {
    if (data < leaf->data) {
        if (leaf->left != nullptr) {
            addNode(data, leaf->left);
        } else {
            leaf->left = new Node;
            leaf->left->data = data;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    } else if (data >= leaf->data) {
        if (leaf->right != nullptr) {
            addNode(data, leaf->right);
        } else {
            leaf->right = new Node;
            leaf->right->data = data;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}

void BST::deleteNode(int data) {
    Node* current = root;
    Node* parent = nullptr;
    bool isLeftChild = false;

    // Find the node to be deleted and its parent
    while (current != nullptr && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
            isLeftChild = true;
        } else {
            current = current->right;
            isLeftChild = false;
        }
    }

    // Node not found
    if (current == nullptr) {
        return;
    }

    // Node is a leaf
    if (current->left == nullptr && current->right == nullptr) {
        if (current == root) {
            root = nullptr;
        } else if (isLeftChild) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
    }
    // Node has a single child (right)
    else if (current->left == nullptr && current->right != nullptr) {
        if (current == root) {
            root = current->right;
        } else if (isLeftChild) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
    }
    // Node has a single child (left)
    else if (current->left != nullptr && current->right == nullptr) {
        if (current == root) {
            root = current->left;
        } else if (isLeftChild) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
    }
    // Node has two children
    else {
        Node* minNode = current->right;
        Node* minNodeParent = current;
        while (minNode->left != nullptr) {
            minNode = minNode->left;
            minNodeParent = minNode;
        }

        current->data = minNode->data;
        if (minNodeParent == current) {
            minNodeParent->right = minNode->right;
        } else {
            minNodeParent->left = minNode->right;
        }
        delete minNode;
    }
}

bool BST::search(int data) {
    Node* current = root;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

void BST::printPreOrder() {
    printPreOrder(root);
}

void BST::printPreOrder(Node* leaf) {
    if (leaf != nullptr) {
        std::cout << leaf->data << " ";
        printPreOrder(leaf->left);
        printPreOrder(leaf->right);
    }
}

void BST::printInOrder() {
    printInOrder(root);
}

void BST::printInOrder(Node* leaf) {
    if (leaf != nullptr) {
        printInOrder(leaf->left);
        std::cout << leaf->data << " ";
        printInOrder(leaf->right);
    }
}

void BST::printPostOrder() {
    printPostOrder(root);
}

void BST::printPostOrder(Node* leaf) {
    if (leaf != nullptr) {
        printPostOrder(leaf->left);
        printPostOrder(leaf->right);
        std::cout << leaf->data << " ";
    }
}

void BST::display() {
    std::cout << "BST:" << std::endl;
    display(root, 0);
}

void BST::display(Node* leaf, int level) {
    if (leaf != nullptr) {
        display(leaf->right, level + 1);
        std::cout << std::setw(3 * level) << ' ';
        std::cout << leaf->data << std::endl;
        display(leaf->left, level + 1);
    }
}
