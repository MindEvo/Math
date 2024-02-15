#include "Tests.h"

void TestAVL() {
    AVLTree tree;

    std::cout << "Pushing value: " << 19 << std::endl;
    tree.insert(10);
    std::cout << "Pushing value: " << 5 << std::endl;
    tree.insert(5);
    std::cout << "Pushing value: " << 15 << std::endl;
    tree.insert(15);
    std::cout << "Pushing value: " << 3 << std::endl;
    tree.insert(3);
    std::cout << "Pushing value: " << 7 << std::endl;
    tree.insert(7);
    std::cout << "Pushing value: " << 12 << std::endl;
    tree.insert(12);
    std::cout << "Pushing value: " << 20 << std::endl;
    tree.insert(20);

    std::cout << "Tree contains 3: " << tree.search(3) << std::endl;
    std::cout << "Tree contains 10: " << tree.search(10) << std::endl;
    std::cout << "Tree contains 15: " << tree.search(15) << std::endl;
    std::cout << "Tree contains 20: " << tree.search(20) << std::endl;
    std::cout << "Tree contains 100: " << tree.search(100) << std::endl;

    tree.remove(10);
    tree.remove(5);
    tree.remove(15);
    tree.remove(3);
    tree.remove(7);
    tree.remove(12);
    tree.remove(20);

    std::cout << "Tree contains 3: " << tree.search(3) << std::endl;
    std::cout << "Tree contains 10: " << tree.search(10) << std::endl;
    std::cout << "Tree contains 15: " << tree.search(15) << std::endl;
    std::cout << "Tree contains 20: " << tree.search(20) << std::endl;
}

// TODO
// void displayPreorder(RedBlackTree::Node *node) {
//     if (node == nullptr) {
//         return;
//     }
//     std::cout << node->key << " ";
//     displayPreorder(node->left);
//     displayPreorder(node->right);
// }

// void displayTree(const RedBlackTree& tree) {
//     displayPreorder(tree.root);
//     std::cout << std::endl;
// }

void TestRBT() {
    RedBlackTree tree;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);

    // insert some random values into the tree
    for (int i = 0; i < 10; i++) {
        int value = dis(gen);
        std::cout << "Inserting value: " << value << std::endl;
        tree.insert(value);
    }

    // TODO
    // displayTree(tree);

    // search for a value in the tree
    int searchKey = dis(gen);
    if (tree.search(searchKey)) {
        std::cout << searchKey << " was found in the tree" << std::endl;
    } else {
        std::cout << searchKey << " was not found in the tree" << std::endl;
    }

    // remove a value from the tree
    int removeKey = dis(gen);
    std::cout << "Removing value: " << removeKey << std::endl;
    tree.remove(removeKey);
}

void TestHEAP() {
    Heap heap;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);

    // add some random values to the heap
    for (int i = 0; i < 10; i++) {
        int value = dis(gen);
        std::cout << "Pushing value: " << value << std::endl;
        heap.push(value);
    }

    // remove all values from the heap
    while (!heap.empty()) {
        std::cout << "Popped value: " << heap.pop() << std::endl;
    }

}

void TestBST() {
    BST tree;

    std::cout << "Pushing value: " << 5 << std::endl;
    tree.addNode(5);
    std::cout << "Pushing value: " << 3 << std::endl;
    tree.addNode(3);
    std::cout << "Pushing value: " << 7 << std::endl;
    tree.addNode(7);
    std::cout << "Pushing value: " << 1 << std::endl;
    tree.addNode(1);
    std::cout << "Pushing value: " << 4 << std::endl;
    tree.addNode(4);
    std::cout << "Pushing value: " << 9 << std::endl;
    tree.addNode(9);
    std::cout << "Pushing value: " << 8 << std::endl;
    tree.addNode(8);
    std::cout << "Pushing value: " << 2 << std::endl;
    tree.addNode(2);
    std::cout << "Pushing value: " << 6 << std::endl;
    tree.addNode(6);

    std::cout << "Pre-order: ";
    tree.printPreOrder();
    std::cout << std::endl;

    std::cout << "In-order: ";
    tree.printInOrder();
    std::cout << std::endl;

    std::cout << "Post-order: ";
    tree.printPostOrder();
    std::cout << std::endl;

    std::cout << "Searching for 5: " << tree.search(5) << std::endl;
    std::cout << "Searching for 10: " << tree.search(10) << std::endl;

    tree.deleteNode(3);
    std::cout << "In-order after deleting 3: ";
    tree.printInOrder();
    std::cout << std::endl;
}