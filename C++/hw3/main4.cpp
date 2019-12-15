#include <iostream>
#include "heapServices.h"
using namespace std;

int main(int argc, char const *argv[]) {
  int arraySize;  // User defined heap size
  int k;
  FourMinHeap<int> heap;

  cout << "Enter Array Size: "; cin >> arraySize;

  for (int i = 0; i < arraySize; i++){
    int newElement = rand() % 47;   // create a random number
    // Insert to a MIN heap.
    heap.insert(newElement);
    heap.printHeap();
  }

  return 0;
}
