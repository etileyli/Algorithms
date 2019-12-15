#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

template <class Comparable>
class MinMaxHeap{
  public:
    MinMaxHeap( int capacity = 100, bool isMin = true );
    bool isEmpty( );
    const Comparable & findMin( ) const;
    void insert(const Comparable & x);
    void newInsert(const Comparable & x);
    void deleteTop( );
    void deleteTop(Comparable &topItem);
    void makeEmpty( );
    void printHeap();
    void printHeapTree();
    int getSize();
    bool compareHeaps(MinMaxHeap<Comparable> heapLbl);
  private:
    int _theSize;  // Number of elements in heap
    bool _isMin;
    vector<Comparable> array;   // The heap array
    void percolateDown( int hole );
    void buildHeap( );
    void insertSpace(int n);
    bool isFirstNode(int index);
};

template <class Comparable>
MinMaxHeap<Comparable>::MinMaxHeap(int capacity, bool isMin){
  _theSize = 0;   // initial size of the heap
  _isMin = isMin; // If the heap is min or max
  array.push_back(0);
}

template <class Comparable>
void MinMaxHeap<Comparable>::newInsert(const Comparable & x){
  array[ 0 ] = x;   // initialize sentinel
  if( _theSize + 1 == array.size( ) )
      array.resize( array.size() * 2 + 1 );

  array[++_theSize] = x;
  buildHeap();
}

template <class Comparable>
void MinMaxHeap<Comparable>::insert(const Comparable & x){
    array[ 0 ] = x;   // initialize sentinel
    if( _theSize + 1 == array.size( ) )
        array.resize( array.size() * 2 + 1 );

    // Percolate up
    int hole = ++_theSize;
    // Min Heap insertion
    if (_isMin)
      for( ; x < array[ hole / 2 ]; hole /= 2 )
          array[ hole ] = array[ hole / 2 ];
    // Max heap insertion
    else
      for( ; x > array[ hole / 2 ]; hole /= 2 )
          array[ hole ] = array[ hole / 2 ];
    array[ hole ] = x;
}

// Remove the smallest item from the priority queue.
// Exit without error if empty.
template <class Comparable>
void MinMaxHeap<Comparable>::deleteTop( ){
    if( isEmpty( ) )
        exit(1);

    array[ 1 ] = array[ _theSize-- ];
    percolateDown(1);
}

template <class Comparable>
void MinMaxHeap<Comparable>::deleteTop(Comparable &topItem){
  if( isEmpty( ) )
      exit(1);

  topItem = array[1];
  array[1] = array[_theSize--];
  percolateDown(1);
}

// Internal method to percolate down in the heap.
// hole is the index at which the percolate begins.
template <class Comparable>
void MinMaxHeap<Comparable>::percolateDown( int hole ){
  int child;
  Comparable tmp = array[ hole ];

  if (_isMin)
    for( ; hole * 2 <= _theSize; hole = child )
    {
      child = hole * 2;
      if( child != _theSize && array[child + 1] < array[child])
         child++;
      if( array[ child ] < tmp )
         array[ hole ] = array[ child ];
      else
         break;
    }
  else
    for( ; hole * 2 <= _theSize; hole = child )
    {
      child = hole * 2;
      if( child != _theSize && array[child + 1] > array[child])
         child++;
      if( array[ child ] > tmp )
         array[ hole ] = array[ child ];
      else
         break;
    }

  array[ hole ] = tmp;
}

// Establish heap-order property from an arbitrary
// arrangement of items. Runs in linear time.
template <class Comparable>
void MinMaxHeap<Comparable>::buildHeap( ){
    for( int i = _theSize / 2; i > 0; i-- )
        percolateDown(i);
}

template <class Comparable>
bool MinMaxHeap<Comparable>::isEmpty( ){
  if (_theSize <= 0)
    return true;
  return false;
}

template <class Comparable>
int MinMaxHeap<Comparable>::getSize(){
  return _theSize;
}

template <class Comparable>
bool MinMaxHeap<Comparable>::compareHeaps(MinMaxHeap<Comparable> heapLbl){
  for (int i = 1; i <= _theSize; ){
    Comparable item1; deleteTop(item1);
    Comparable item2; heapLbl.deleteTop(item2);
    cout << "item1 = " << item1 << " and ";
    cout << "item2 = " << item2 << endl;
  if (item1 != item2)
    return false;
  }

  return true;
}

template <class Comparable>
void MinMaxHeap<Comparable>::insertSpace(int n){
  for (int i = 0; i < n; i++)
    cout << " ";
}

template <class Comparable>
bool MinMaxHeap<Comparable>::isFirstNode(int index){
  int nodeDepth = floor(log2(index));
  if ( (log2(index) - nodeDepth) == 0)
    return true;
  return false;
}

template <class Comparable>
void MinMaxHeap<Comparable>::printHeap(){
  cout << "[ ";
  for (int i = 1; i <= _theSize; i++)
    cout << array[i] << " " ;
  cout << "]\n";
}

template <class Comparable>
void MinMaxHeap<Comparable>::printHeapTree(){
  int depth = floor(log2(_theSize));  // depth of the tree
  int nodeDepth = 0;    // depth of the node
  int tabCount = 0;     // tab count to insert
  cout << "The size is " << _theSize << endl;
  cout << "The depth is " << depth << endl;

  // create a file to print heap as a tree
  ofstream treeFile;
  treeFile.open("printTree.txt");

  for (int index = 1; index <= _theSize; index++){
    nodeDepth = floor(log2(index));   //  calculate node depth
    tabCount = pow(2, (depth - nodeDepth) + 1) - 1;   // calculate tab count for node
    if (isFirstNode(index)){  // check if the node is first in row
      treeFile << endl;
      tabCount = pow(2, (depth - nodeDepth)) - 1;
    }
    // insert tabs before the nodeDepth
    for (int i = 0; i < tabCount; i++)
      treeFile << "\t";
    treeFile << setfill('0') << setw(2) << array[index];   // insert node value
  }

  treeFile.close();
}
