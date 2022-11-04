#include <iostream>
void CollatzConjecture(int n);
void Test2();

int main() {
    Test2();

    return 0;
}

void CollatzConjecture(int n) {
    while(n != 1) {
        if (n % 2 == 0) {n = n/2; std::cout << n << '\n';}
        else {n = 3 * n + 1; std::cout << n << '\n';}
    }    
}

void Test2() {
    int n;
    std::cout << "Enter the number: ";
    std::cin >> n;
    CollatzConjecture(n);
}