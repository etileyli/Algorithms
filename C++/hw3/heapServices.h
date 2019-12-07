#include <iostream>
#include <vector>
using namespace std;

template <class MinMaxHeap>
class BinaryHeap
{
  public:
    BinaryHeap( int capacity = 100, bool isMin = true );
    bool isEmpty( ) const;
    const MinMaxHeap & findMin( ) const;

    void insert( const MinMaxHeap & x );
    void deleteMin( );
    void deleteMin( MinMaxHeap & minItem );
    void makeEmpty( );

  private:
    int _theSize;  // Number of elements in heap
    bool _isMin;
    vector<MinMaxHeap> array;   // The heap array
    void buildHeap( );
    void percolateDown( int hole );
};

template <class MinMaxHeap>
BinaryHeap<MinMaxHeap>::BinaryHeap(int capacity, bool isMin){
  _theSize = capacity;
  _isMin = isMin;
}


// Insert item x into the priority queue, maintaining heap order.
// Duplicates are allowed.
template <class MinMaxHeap>
void BinaryHeap<MinMaxHeap>::insert( const MinMaxHeap & x )
{
    array[ 0 ] = x;   // initialize sentinel
    if( _theSize + 1 == array.size( ) )
        array.resize( array.size( ) * 2 + 1 );

    // Percolate up
    int hole = ++_theSize;
    for( ; x < array[ hole / 2 ]; hole /= 2 )
        array[ hole ] = array[ hole / 2 ];
    array[ hole ] = x;
}

// Remove the smallest item from the priority queue.
// Exit without error if empty.
template <class MinMaxHeap>
void BinaryHeap<MinMaxHeap>::deleteMin( )
{
    if( isEmpty( ) )
        exit(1);

    array[ 1 ] = array[ _theSize-- ];
    percolateDown( 1 );
}

// Internal method to percolate down in the heap.
// hole is the index at which the percolate begins.
template <class MinMaxHeap>
void BinaryHeap<MinMaxHeap>::percolateDown( int hole )
{
  int child;
  MinMaxHeap tmp = array[ hole ];

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
  array[ hole ] = tmp;
}

// Establish heap-order property from an arbitrary
// arrangement of items. Runs in linear time.
template <class MinMaxHeap>
void BinaryHeap<MinMaxHeap>::buildHeap( )
{
    for( int i = _theSize / 2; i > 0; i-- )
        percolateDown( i );
}
