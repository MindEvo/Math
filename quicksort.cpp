#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <tuple>
#include <atomic>

template <typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

size_t Partition(size_t low, size_t high, int *a) {
    size_t i, j; 
    int pivot;
    pivot = a[low];
    i = low;
    j = high;
    while(i < j) {
        do {
            i++;
        } while(a[i] <= pivot);

        // ?? MODIFY HERE TO FIX LAST INDEX NOT SORTING ?? //
        do {
            j--;
        } while(a[j] > pivot);
        /////////////////////////////////////////////////////

        if (i < j)
            Swap(a[i], a[j]);
    }
    Swap(a[low], a[j]);
    return j;
}

void Quicksort(size_t low, size_t high, int *a) {
    if (low < high) {
        size_t j;
        j = Partition(low, high, a);

        Quicksort(low, j, a);
        Quicksort(j + 1, high, a);
    }
}

int main() {
    std::array<int, 32> a = {
        3,2,44,5,6,17,9,51,
        81,21,23,11,34,78,94,1,
        17,45,91,82,103,16,255,200,
        101,102,99,7,13,18,22,33
    };
    Quicksort(0, 31, &a.front());
    for (int i=0; i<32; i++) std::cout << a[i] << '\n';

    return 0;
}