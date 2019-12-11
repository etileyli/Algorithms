#include <iostream>
#include "heapServices.h"
using namespace std;

int main(int argc, char const *argv[]) {

  int heapSize; // User defined heap size
  int k;        // User defined greatest/smallest item count
  MinMaxHeap<int> heap;

  // Get user defined inputs
  cout << "Enter Heap Size: "; cin >> heapSize;
  cout << "Enter k: "; cin >> k;

  // k-Greatest elements solution
  // Create a k-size min heap and remove root element (minimum of k elements)
  // This way the remaining elements will always be largest k of all elements.
  for (int i = 0; i < heapSize; i++){
    int newElement = rand() % 47;   // create a random number
    // Insert to a MIN heap. Min element stands at the top
    heap.insert(newElement);
    // when MIN heap size is larger than k, delete minimum of k numbers
    if (heap.getSize() > k)
      heap.deleteMin();
  }
  heap.printHeap();

  return 0;
}
