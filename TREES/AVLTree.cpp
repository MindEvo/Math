// AVLTree.cpp
#include "AVLTree.h"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree()
{
    // Use a recursive helper function to free the memory
    // of all the nodes in the tree
    deleteTree(root);
}

void AVLTree::deleteTree(Node* node)
{
    if (!node)
    {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int AVLTree::height(Node* node) const
{
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(Node* node) const
{
    return height(node->right) - height(node->left);
}

void AVLTree::updateHeight(Node* node)
{
    node->height = std::max(height(node->left), height(node->right)) + 1;
}

AVLTree::Node* AVLTree::rotateRight(Node* node)
{
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    updateHeight(node);
    updateHeight(temp);
    return temp;
}

AVLTree::Node* AVLTree::rotateLeft(Node* node)
{
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    updateHeight(node);
    updateHeight(temp);
    return temp;
}

AVLTree::Node* AVLTree::fixBalance(Node* node)
{
    updateHeight(node);

    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->right) < 0)
        {
            node->right = rotateRight(node->right);
        }
        node = rotateLeft(node);
    }
    else if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->left) > 0)
        {
            node->left = rotateLeft(node->left);
        }
        node = rotateRight(node);
    }

    return node;
}

void AVLTree::insert(int value)
{
    root = insert(root, value);
}

AVLTree::Node* AVLTree::insert(Node* node, int value)
{
    if (!node)
    {
        return new Node(value);
    }

    if (value < node->value)
    {
        node->left = insert(node->left, value);
    }
    else
    {
        node->right = insert(node->right, value);
    }

    return fixBalance(node);
}

void AVLTree::remove(int value)
{
    root = remove(root, value);
}

AVLTree::Node* AVLTree::remove(Node* node, int value)
{
    if (!node)
    {
        return nullptr;
    }

    if (value < node->value)
    {
        node->left = remove(node->left, value);
    }
    else if (value > node->value)
    {
        node->right = remove(node->right, value);
    }
    else
    {
        if (!node->left && !node->right)
        {
            delete node;
            return nullptr;
        }
        else if (!node->left)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else
        {
            Node* temp = findMin(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
    }

    return fixBalance(node);
}

bool AVLTree::search(int value) const
{
    Node* node = root;
    while (node)
    {
        if (node->value == value)
        {
            return true;
        }
        else if (value < node->value)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return false;
}

AVLTree::Node* AVLTree::findMin(Node* node) const
{
    while (node->left)
    {
        node = node->left;
    }
    return node;
}
