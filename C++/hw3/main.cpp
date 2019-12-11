#include <iostream>
#include "heapServices.h"
using namespace std;

int main(int argc, char const *argv[]) {

  int heapSize = 6;
  int k;
  MinMaxHeap<int> heap;

  // int heapSize = 6;
  // heap.insert(5);
  // cout << "****" << endl;
  // heap.printHeap();
  //
  // heap.insert(7);
  // cout << "****" << endl;
  // heap.printHeap();
  //
  // heap.insert(10);
  // cout << "****" << endl;
  // heap.printHeap();
  //
  // heap.insert(4);
  // cout << "****" << endl;
  // heap.printHeap();
  //
  // heap.insert(8);
  // cout << "****" << endl;
  // heap.printHeap();


  cout << "Enter Heap Size: "; cin >> heapSize;
  cout << "Enter k: "; cin >> k;
  for (int i = 0; i < heapSize; i++){
    cout << "For i = " << i << endl;
    int newElement = rand() % 40;
    cout << "New Element: " << newElement <<endl;
    heap.insert(newElement);
    if (heap._theSize > k)
      heap.deleteMin();
  }
  heap.printHeap();

  return 0;
}
