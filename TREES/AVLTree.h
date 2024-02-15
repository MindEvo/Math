// AVLTree.h
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <cstdlib>
#include <algorithm>

class AVLTree
{
public:
    AVLTree();
    ~AVLTree();

    void insert(int value);
    void remove(int value);
    bool search(int value) const;

private:
    struct Node
    {
        int value;
        int height;
        Node* left;
        Node* right;

        Node(int value) : value(value), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void deleteTree(Node* node);

    int height(Node* node) const;
    int balanceFactor(Node* node) const;
    void updateHeight(Node* node);
    Node* fixBalance(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeft(Node* node);
    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value);
    Node* findMin(Node* node) const;
};

#endif // AVL_TREE_H
