#include <iostream>
#include "heapServices.h"
using namespace std;

int main(int argc, char const *argv[]) {

  int heapSize = 6;
  MinMaxHeap<int> heap;

  heap.insert(5);
  cout << "****" << endl;
  heap.printHeap();

  heap.insert(7);
  cout << "****" << endl;
  heap.printHeap();

  heap.insert(10);
  cout << "****" << endl;
  heap.printHeap();

  heap.insert(4);
  cout << "****" << endl;
  heap.printHeap();

  heap.insert(8);
  cout << "****" << endl;
  heap.printHeap();
  // for (int i = 0; i < heapSize; i++){
  //   cout << "For i = " << i << endl;
  //   heap.insert(rand()%11);
  //   heap.printHeap();
  // }

  return 0;
}
