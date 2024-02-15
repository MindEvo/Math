#include <vector>
#include <utility> // For std::pair
#include <iostream>

std::pair<int, int> findElement(const std::vector<std::vector<int>>& A, int x) {
    if (A.empty() || A.front().empty()) return {-1, -1}; // Handle empty matrix

    size_t n = A.size(); // Use size_t for size-related variables
    size_t i = n - 1, j = 0;

    while (i < n && j < A[i].size()) { // Ensure j is within bounds
        if (A[i][j] == x) {
            return {static_cast<int>(i), static_cast<int>(j)}; // Found
        } else if (A[i][j] < x) {
            ++j; // Move right
        } else {
            --i; // Move up, with check to avoid underflow
        }
    }

    return {-1, -1}; // Not found
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 6, 11, 16, 21},
        {2, 7, 12, 17, 22},
        {3, 8, 13, 18, 23},
        {4, 9, 14, 19, 24},
        {5, 10, 15, 20, 25}
    };

    // Show the matrix in the terminal
    for (const auto& row : matrix) {
        for ( const auto& col : row) {
            std::cout << col << " ";
        }
        std::cout << "\n";
    }



    // Allow the user to search for any particular element
    bool ask = true;
    int x;
    do {
        std::cout << "Enter number to search for OR zero to exit: ";
        std::cin >> x;
        if(x == 0) {
            ask = false;
            std::cout << "\nExiting...\n";
            break;
        }
        std::pair<int, int> resultUser = findElement(matrix, x);
        if (resultUser.first == -1 && resultUser.second == -1) {
            std::cout << "Num not found!\n";
        }
        else {
            std::cout << "Found at: " << resultUser.first << ", " << resultUser.second << "\n";
        }
    } while (ask == true);
    
    return 0;
}