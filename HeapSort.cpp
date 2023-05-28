#include<iostream>
#include"Header.h"
using namespace std;

int main()
{
    Heap heap;
    const int MAX = 10;
    int arr[MAX] = { 4,3,2,6,10,24,15 };
    int n = 7;

    
    /*heap.buildMaxHeap(arr, n);
    heap.insert_value_maxHeap(arr,9,n);
    heap.extract_maximum(arr, n);
    heap.ascendingHeapSort(arr, n);*/

    
    heap.buildMinHeap(arr, n);
    heap.insert_value_minHeap(arr,1, n);
    heap.descendingHeapSort(arr, n);
    heap.extract_minimum(arr,n);
    heap.printArray(arr, n);
    return 0;
}

/*class PQueue {
public:
    PQueue() : n(0) {}

    void push(int val);
    int pop();
    void print() { heap.printArray(arr, n); }
private:
    Heap heap;
    int arr[1000];
    int n;
};

void PQueue::push(int val) {
    heap.insert_value_maxHeap(arr, val, n);
}*/