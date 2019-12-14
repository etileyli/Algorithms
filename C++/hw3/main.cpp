#include <iostream>
#include "heapServices.h"
using namespace std;

int main(int argc, char const *argv[]) {

  int arraySize; // User defined heap size
  int k;        // User defined greatest/smallest item count
  MinMaxHeap<int> heap;

  // Get user defined inputs
  cout << "Enter Heap Size: "; cin >> arraySize;
  cout << "Enter k: "; cin >> k;

  // // k-Greatest elements solution
  // // Create a k-size min heap and remove root element (minimum of k elements)
  // // This way the remaining elements will always be largest k of all elements.
  // for (int i = 0; i < arraySize; i++){
  //   int newElement = rand() % 47;   // create a random number
  //   cout << newElement << endl;
  //   // Insert to a MIN heap. Min element stands at the top
  //   heap.insertMaxHeap(newElement);
  //   // when MIN heap size is larger than k, delete minimum of k numbers
  //   // cout << "_theSize = " << heap.getSize()<< endl;
  //   if (heap.getSize() > k)
  //     heap.deleteMin();
  //     heap.printHeap();
  // }

  for (int i = 0; i < arraySize; i++){
    int newElement = rand() % 47;   // create a random number
    cout << newElement << endl;
    // Insert to a Max heap. Max element stands at the top
    heap.insertMinHeap(newElement);
    // when MAX heap size is larger than k, delete Max of k numbers
    if (heap.getSize() > k)
      heap.deleteMax();
    heap.printHeap();
  }

  return 0;
}
