#include <iostream>
#include <vector>

void GetVecInput(std::vector<int> &v);
void CrossProduct(std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &cross);
void PrintResult(const std::vector<int> &v1, const std::vector<int> &v2, const std::vector<int> &cross);

int main() {
    std::vector<int> v1, v2, cross;

    std::cout << "First vector\n";
    GetVecInput(v1);
    std::cout << "Second vector\n";
    GetVecInput(v2);

    CrossProduct(v1, v2, cross);
    PrintResult(v1, v2, cross);
    return 0;
}

void CrossProduct(std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &cross) {
    cross.push_back(v1[1]*v2[2] - v1[2]*v2[1]);
    cross.push_back(v1[2]*v2[0] - v1[0]*v2[2]);
    cross.push_back(v1[0]*v2[1] - v1[1]*v2[0]);
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

void PrintResult(const std::vector<int> &v1, const std::vector<int> &v2, const std::vector<int> &cross) {
    std::cout << "\nThe Cross Product of "
            << "[" << v1[0] << ", " << v1[1] << ", " << v1[2] << "]"
            << " and "
            << "[" << v2[0] << ", " << v2[1] << ", " << v2[2] << "]"
            << " is: "
            << "[" << cross[0] << ", " << cross[1] << ", " << cross[2] << "]\n\n";
}