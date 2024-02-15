#ifndef BST_H
#define BST_H

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    void addNode(int data, Node* leaf);
    void freeNode(Node* leaf);
    void printPreOrder(Node* leaf);
    void printInOrder(Node* leaf);
    void printPostOrder(Node* leaf);
    void display(Node* leaf, int level);

public:
    BST();
    ~BST();

    void addNode(int data);
    void deleteNode(int data);
    bool search(int data);

    void printPreOrder();
    void printInOrder();
    void printPostOrder();
    void display();
};

#endif
