#include <iostream>
#include "heapServices.h"
using namespace std;

int main(int argc, char const *argv[]) {
  int arraySize;  // User defined heap size
  MinMaxHeap<int> heap(100, true);

  cout << "Enter Array Size: "; cin >> arraySize;

  // Use insert function to fill heap1
  for (int i = 0; i < arraySize; i++ ){
      int element = rand() % 100;
      heap.insert(element);
  }

  heap.printHeap();
  heap.printHeapTree();

  return 0;
}
