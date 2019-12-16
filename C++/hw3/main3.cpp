/*
  Solution for 1-e
  The output is printTree.txt
  Deletion is on the same file (printTree.txt)
*/

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
  heap.indentedPrint();

  int delNodeCount = 0;
  cout << "Enter the node count to be deleted from tree: "; cin >> delNodeCount;
  if (delNodeCount >= arraySize){
    cout << "Nodes to be deleted should be smaller than heap size. The program will exit.";
    return 1;
  }

  for (int i = 0; i < delNodeCount; i++)
    heap.deleteTop();

  heap.printHeap();
  heap.indentedPrint();

  return 0;
}
