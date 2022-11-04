//////////////////////////////////////////////////////////////////////////////////////////////
// Write a function that has two pointers as arguments. 
// The pointers passed to this function should each point to a dynamic array
// that has been filled with 5 random numbers For example:
//
// pointer1 points to {1, 5, 6, 88, 9}
// pointer2 points to {9, 7, 90, 3, 2]

// This function will return an array that has combined the two arrays.  For example:
// {1, 5, 6, 88, 9, 9, 7, 90, 3, 2}
// In your main function, write a test to confirm your function is working correctly.
//////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdlib.h>

int GenerateRandomNumber(int range);
void FillArray(int* a, size_t size);
void PrintArray(int* a, size_t size);
int* ArrayUnion(int *a1, size_t size1, int *a2, size_t size2);

int main() {
    srand(time(NULL));
    int *a1, *a2;
    size_t size = 5;
    a1 = new int[size];
    a2 = new int[size];
    FillArray(a1, size);
    FillArray(a2, size);

    // This is ugly.
    int *a1a2;
    a1a2 = new int[size * 2];
    a1a2 = ArrayUnion(a1, size, a2, size);
    PrintArray(a1a2, size * 2);
    //
    return 0;
}

/*************************************
* GenerateRandomNumber
*
* Requires a random time seed to be generated in main prior to call.
**************************************/

int GenerateRandomNumber(int range) {
    int num;
    num = rand()%range;
    return num;
}

/*************************************
* FillArray
**************************************/

void FillArray(int* a, size_t size) {
    for (int i=0; i<size; ++i) {
        *(a+i) = GenerateRandomNumber(100);
    }
}

/*************************************
* PrintArray
**************************************/

void PrintArray(int* a, size_t size) {
    std::cout << "[";
    for (int i=0; i<size - 1; ++i) {
        std::cout << *(a+i)
                << ", ";
    }
    std::cout << *(a + size - 1) << "]\n";
}

/*************************************
* ArrayUnion
**************************************/

int* ArrayUnion(int *a1, size_t size1, int *a2, size_t size2) {
    int *a1a2 = new int[size1 + size2];
    for (int i=0; i<size1; ++i)
        *(a1a2+i) = *(a1+i);
    for (int i=0; i<size2; ++i)
        *(a1a2+size1+i)= *(a2+i);
    return a1a2;
}