/*
 k-Greatest elements and k-Smallest elements solutions
 Solutions for homework 1-b & 1-c
 */

#include <iostream>
#include "heapServices.h"
using namespace std;

int main(int argc, char const *argv[]) {

  int arraySize; // User defined heap size
  int k;        // User defined greatest/smallest item count
  MinMaxHeap<int> minHeap(100, true);   // TRUE -> MINHEAP
  MinMaxHeap<int> maxHeap(100, false);  // FALSE-> MAXHEAP

  // k-Greatest elements solution
  // Create a k-size min heap and remove root element (minimum of k elements)
  // This way the remaining elements will always be largest k of all elements.

  // Get user defined inputs
  cout << "k-Greatest elements solution" << endl;
  cout << "Enter Array Size: "; cin >> arraySize;
  cout << "Enter k: "; cin >> k;

  for (int i = 0; i < arraySize; i++){
    int newElement = rand() % 47;   // create a random number
    cout << "New Item: " << newElement << endl;
    // Insert to a MIN heap. Min element stands at the top
    minHeap.insert(newElement);
    // when MIN heap size is larger than k, delete minimum of k numbers
    // cout << "_theSize = " << heap.getSize()<< endl;
    if (minHeap.getSize() > k)
      minHeap.deleteTop();
    cout << "The heap:   ";
    minHeap.printHeap();
  }

  // k-Smallest elements solution
  cout << "k-Smallest elements solution" << endl;
  cout << "Enter Array Size: "; cin >> arraySize;
  cout << "Enter k: "; cin >> k;

  for (int i = 0; i < arraySize; i++){
    int newElement = rand() % 47;   // create a random number
    cout << "New Item: " << newElement << endl;
    // Insert to a Max heap. Max element stands at the top
    maxHeap.insert(newElement);
    // when MAX heap size is larger than k, delete Max of k numbers
    if (maxHeap.getSize() > k)
      maxHeap.deleteTop();
    cout << "The heap:   ";
    maxHeap.printHeap();
  }

  return 0;
}
