#include "Tests.h"

int main() {
    char choice;
    std::cout << "TEST BINARY SEARCH TREES (1)\n"
            << "TEST HEAPS (2)\n"
            << "TEST RED BLACK TREES (3)\n"
            << "TEST AVL TREES (4)\n"
            << "Enter choice: ";
    std::cin >> choice;
    std::cout << "\n";

    switch (choice) {
        case '1':
            TestBST();
            break;
        case '2':
            TestHEAP();
            break;
        case '3':
            TestRBT();
            break;
        case '4':
            TestAVL();
            break;
        default:
            break;
    }

    return 0;
}