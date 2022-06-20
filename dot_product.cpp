#include <iostream>
#include <vector>

void GetVecInput(std::vector<int> &v);
void DotProduct(std::vector<int> &v1, std::vector<int> &v2, int &dot);
void PrintResult(const std::vector<int> &v1, const std::vector<int> &v2, const int &dot);

int main() {
    std::vector<int> v1, v2;
    int dot;

    std::cout << "First vector\n";
    GetVecInput(v1);
    std::cout << "Second vector\n";
    GetVecInput(v2);

    DotProduct(v1, v2, dot);
    PrintResult(v1, v2, dot);
    return 0;
}

void DotProduct(std::vector<int> &v1, std::vector<int> &v2, int &dot) {
    dot = v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}

void GetVecInput(std::vector<int> &v) {
    int input;
    std::cout << "X value: ";
    std::cin >> input;
    v.push_back(input);
    std::cout << "Y value: ";
    std::cin >> input;
    v.push_back(input);
    std::cout << "Z value: ";
    std::cin >> input;
    v.push_back(input);
}

void PrintResult(const std::vector<int> &v1, const std::vector<int> &v2, const int &dot) {
    std::cout << "\nThe Dot Product of "
            << "[" << v1[0] << ", " << v1[1] << ", " << v1[2] << "]"
            << " and "
            << "[" << v2[0] << ", " << v2[1] << ", " << v2[2] << "]"
            << " is: " << dot << "\n\n";
}