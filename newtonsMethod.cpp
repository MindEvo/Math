/*
===================================================
Newton's Method for acquiring the root of a number.
E.g. x*x = n
Where n is the number whose roots 
you are searching for.
===================================================
*/
#include <iostream>
using std::cout, std::cin;

float newtonsMethod(int n, float guess);
void test();

int main() {
    test();
    return 0;
}

float newtonsMethod(int n, float guess) {
    for (int i = 0; i < 5; ++i) {
        guess -= (guess * guess - n) / (2 * guess);
    }
    return guess;
}

void test() {
    int n; float guess;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Enter your guess for the root of number: ";
    cin >> guess;
    cout << newtonsMethod(n, guess);
}