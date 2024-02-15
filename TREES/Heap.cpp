#include "heap.h"

#include <algorithm>

Heap::Heap() {
}

Heap::Heap(const std::vector<int>& values) : heap(values) {
    // heapify all internal nodes, from last internal node to root
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
        heapifyDown(i);
    }
}

void Heap::push(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int Heap::pop() {
    int min = heap.front();
    std::swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    heapifyDown(0);
    return min;
}

int Heap::peek() const {
    return heap.front();
}

bool Heap::empty() const {
    return heap.empty();
}

int Heap::size() const {
    return heap.size();
}

void Heap::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[parent] > heap[index]) {
        std::swap(heap[parent], heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void Heap::heapifyDown(int index) {
    int child = 2 * index + 1;
    while (child < heap.size()) {
        if (child + 1 < heap.size() && heap[child + 1] < heap[child]) {
            child++;
        }
        if (heap[index] > heap[child]) {
            std::swap(heap[index], heap[child]);
            index = child;
            child = 2 * index + 1;
        } else {
            break;
        }
    }
}
