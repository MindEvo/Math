#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap {
public:
    Heap();
    explicit Heap(const std::vector<int>& values);

    void push(int value);
    int pop();
    int peek() const;
    bool empty() const;
    int size() const;

private:
    std::vector<int> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);
};

#endif
