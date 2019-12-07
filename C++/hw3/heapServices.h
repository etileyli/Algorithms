#include <iostream>
#include <vector>
using namespace std;

template <class Comparable>
class BinaryHeap
{
  public:
    BinaryHeap( int capacity = 100 );
    bool isEmpty( ) const;
    const Comparable & findMin( ) const;

    void insert( const Comparable & x );
    void deleteMin( );
    void deleteMin( Comparable & minItem );
    void makeEmpty( );

  private:
    int theSize;  // Number of elements in heap
    vector<Comparable> array;   // The heap array
    void buildHeap( );
    void percolateDown( int hole );
};

template <class Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity){

}


// Insert item x into the priority queue, maintaining heap order.
// Duplicates are allowed.
template <class Comparable>
void BinaryHeap<Comparable>::insert( const Comparable & x )
{
    array[ 0 ] = x;   // initialize sentinel
    if( theSize + 1 == array.size( ) )
        array.resize( array.size( ) * 2 + 1 );

    // Percolate up
    int hole = ++theSize;
    for( ; x < array[ hole / 2 ]; hole /= 2 )
        array[ hole ] = array[ hole / 2 ];
    array[ hole ] = x;
}

// Remove the smallest item from the priority queue.
// Exit without error if empty.
template <class Comparable>
void BinaryHeap<Comparable>::deleteMin( )
{
    if( isEmpty( ) )
        exit(1);

    array[ 1 ] = array[ theSize-- ];
    percolateDown( 1 );
}

// Internal method to percolate down in the heap.
// hole is the index at which the percolate begins.
template <class Comparable>
void BinaryHeap<Comparable>::percolateDown( int hole )
{
  int child;
  Comparable tmp = array[ hole ];

  for( ; hole * 2 <= theSize; hole = child )
  {
    child = hole * 2;
    if( child != theSize && array[child + 1] < array[child])
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
template <class Comparable>
void BinaryHeap<Comparable>::buildHeap( )
{
    for( int i = theSize / 2; i > 0; i-- )
        percolateDown( i );
}
