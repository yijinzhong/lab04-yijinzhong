// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;


void percolateUp(std::vector<int>& vdata, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (vdata[i] < vdata[parent]) {
            std::swap(vdata[i], vdata[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

void percolateDown(std::vector<int>& vdata, int i) {
    int size = vdata.size();
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && vdata[left] < vdata[smallest])
            smallest = left;
        if (right < size && vdata[right] < vdata[smallest])
            smallest = right;

        if (smallest != i) {
            std::swap(vdata[i], vdata[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
      vdata.assign(start, end);
    int size = vdata.size();
    
    for (int i = (size - 2) / 2; i >= 0; i--) {
        percolateDown(vdata, i);
    }
}



// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
       vdata.push_back(value);
    percolateUp(vdata, vdata.size() - 1);
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
     if (empty()) return;
    vdata[0] = vdata.back();
    vdata.pop_back();
    if (!empty())
        percolateDown(vdata, 0);
}

// Returns the minimum element in the heap
int Heap::top(){
      return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
      return vdata.empty();
}
    