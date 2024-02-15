#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

class RedBlackTree {
public:
    enum class Color { RED, BLACK };

    struct Node {
        int key;
        Color color;
        Node *left;
        Node *right;
        Node *parent;

        explicit Node(int key);
    };

    RedBlackTree();
    ~RedBlackTree();

    void insert(int key);
    void remove(int key);
    bool search(int key) const;
    

private:
    Node *root;

    Node *minimum(Node *node) const;
    Node *maximum(Node *node) const;
    Node *successor(Node *node) const;
    Node *predecessor(Node *node) const;

    void rotateLeft(Node *node);
    void rotateRight(Node *node);
    void fixUp(Node *node);
};

#endif
