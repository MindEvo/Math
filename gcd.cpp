#include<iostream>

int GreatestCommonDivisor(int i1, int i2);

int main() {
    int x, y, result;
    std::cout << "Enter first number: ";
    std::cin >> x;
    std::cout << "Enter second number: ";
    std::cin >> y;
    result = GreatestCommonDivisor(x, y);
    std::cout << result;

    return 0;
}

int GreatestCommonDivisor(int i1, int i2) {
    if (i1 > i2) {
        if (i2 == 0) {
            return (i1);
        }
        return GreatestCommonDivisor(i2, i1 % i2);
    }
    else {
        if (i1 ==0) {
            return (i2);
        }
        return GreatestCommonDivisor(i1, i2 % i1);
    }
}
