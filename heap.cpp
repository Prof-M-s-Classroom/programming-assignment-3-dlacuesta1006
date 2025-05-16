#include "heap.h"
#include <climits>
#include <algorithm>

MinHeap::MinHeap(int cap) {
    capacity = cap;
    size = 0;
    heapArray = new int[cap];
    keyArray = new int[cap];
    position = new int[cap];

    for (int i = 0; i < cap; i++) {
        keyArray[i] = INT_MAX;
        heapArray[i] = i;
        position[i] = i;
    }
}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

bool MinHeap::isEmpty() {
    return size == 0;
}

void MinHeap::insert(int vertex, int key) {
    keyArray[vertex] = key;
    heapArray[size] = vertex;
    position[vertex] = size;
    int i = size++;

    while (i && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        std::swap(heapArray[i], heapArray[(i - 1) / 2]);
        position[heapArray[i]] = i;
        position[heapArray[(i - 1) / 2]] = (i -1) / 2;
        i = (i - 1) / 2;
    }
}

void MinHeap::minHeapify(int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]])
        smallest = left;

    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]])
        smallest = right;

    if (smallest != idx) {
        std::swap(heapArray[idx], heapArray[smallest]);
        position[heapArray[idx]] = idx;
        position[heapArray[smallest]] = smallest;
        minHeapify(smallest);
    }
}

int MinHeap::extractMin() {
    if (size == 0)
        return -1;

    int root = heapArray[0];
    heapArray[0] = heapArray[size - 1];
    position[heapArray[0]] = 0;
    size--;
    minHeapify(0);

    return root;
}

void MinHeap::decreaseKey(int vertex, int newKey) {
    int i = position[vertex];
    keyArray[vertex] = newKey;

    while (i && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        std::swap(heapArray[i], heapArray[(i - 1) / 2]);
        position[heapArray[i]] = i;
        position[heapArray[(i - 1) / 2]] = (i - 1) / 2;
        i = (i - 1) / 2;
    }
}

bool MinHeap::isInMinHeap(int vertex) {
    return position[vertex] < size;
}


