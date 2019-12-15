#include <iostream>
#include "heapServices.h"
using namespace std;

int main(int argc, char const *argv[]) {
  int arraySize; // User defined heap size
  MinMaxHeap<int> heap1(100, true), heap2(100, true);

  cout << "Enter Array Size: "; cin >> arraySize;

  // Use insert function to fill heap1
  for (int i = 0; i < arraySize; i++ ){
      int element = rand() % 42;
      heap1.insert(element);
      heap2.newInsert(element);
  }

  heap1.printHeap();
  heap2.printHeap();

  if (heap1.compareHeaps(heap2))
    cout << "Heaps are the same!" << endl;
  else
    cout << "Heaps are different!" << endl;


  return 0;
}
