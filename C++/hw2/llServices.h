#include <iostream>
using namespace std;

template <class T>
  class Node{
  private:
    Node<T> *head;

  public:
    Node (const T& e = T(), Node *n = NULL):
        element(e), next(n){}

    T element;
    Node *next;
  };

template <class T>
  class List{
  private:
    Node<T>* dummyHead;
  public:
    List(){dummyHead = new Node<T>(T(), NULL);}

    ~List(){
      makeEmpty();
      delete dummyHead;
    }

    List<T>& operator=(const List& rhs){
      if (this != &rhs){
        makeEmpty();
        const Node<T>* r = rhs.first();
        Node<T>* p = zeroth();

        while(r){
          insert(r->element, p);
          r = r->next;
          p = p->next;
        }
      }
      return *this;
    }

    // copy constructor
    List(const List& rhs){
      dummyHead = new Node<T>(T(), NULL);
      *this = rhs;  // use operator=
    }
    Node<T>* zeroth(){return dummyHead;}

    Node<T>* first(){return dummyHead->next;}

    const Node<T>* first() const {return dummyHead->next;}

    bool isEmpty(){return first() == NULL;}

    // For insertion
    // 1-define a new node
    // 2-make it point the node pointed by previous node
    // 3-make previous node to point new node.
    void insert(const T& data, Node<T>* p){
      Node<T>* newNode = new Node<T>(data, p->next);
      p->next = newNode;
    }

    Node<T>* find(const T& data){
      Node<T>* p = first();

      while(p){
        if (p->element == data)
          return p;
        p = p-> next;
      }
      return NULL;
    }

    Node<T>* findPrevious(const T& data){
      Node<T>* p = zeroth();

      while(p->next){
        if (p->next->element == data)
          return p;
        p = p->next;
      }
      return NULL;
    }

    // For removal
    // 1-find previous
    // 2-make previous point to next
    void remove(const T& data){
      Node<T>* p = findPrevious(data);

      if (p){
        Node<T>* temp = p->next;
        p->next = temp->next;
        delete temp;
      }
    }

    void print(){
      Node<T>* p = first();

      while(p){
        cout << p->element << endl;
        p = p->next;
      }
    }

    void makeEmpty(){
      while(!isEmpty()){
        remove(first()->element);
      }
    }



    // void swap( T &lhs, T &rhs )
    // {
    // 	T tmp = lhs;
    // 	lhs = rhs;
    // 	rhs = tmp;
    // }

    void swap(Node<T>* val1, Node<T>* val2){
      Node<T>* temp = val2;
      insert(val1->element, val2);
      remove(val2->element);
      insert(temp->element, val1);
      remove(val1->element);
      print();
    }

    void selectionSort(){
      Node<T>* p = first();

      int k = 1;
      while(p->next){
        cout << "******Cycle " << k++ << endl;
        Node<T>* minNode = p;
        Node<T>* p2 = p->next;
        cout << "p->element = " << p->element << endl;
        cout << "p2->element = " << p2->element << endl;
        while(p2){
          if (p2->element < minNode->element){
            // cout << "p2->element = " << p2->element << " minNode->element = " << minNode->element << endl;
            minNode = p2;
          }
          // cout << p2->element << endl;
          p2 = p2->next;
        }
        cout << "Min updated to " << minNode->element << endl;
        cout << "Swapping element " << p->element << " with element " << minNode->element << endl;
        swap(p, minNode);

        // print();
        p = p->next->next;
        cout << "End of cycle " << k << " p->element = " << p->element << endl;
      }
    }

    void selectionSort(T a[], int n) {
      for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++)
           if (a[j] < a[min]) min = j;
        swap(a[i], a[min]);
      }
    }

  };

// Test program for llServices. Change file extension from .h to .cpp to execute
// int main(int argc, char const *argv[]) {
//
//   List<int> list1, list2;
//   Node<int>* p;
//
//   int list1Length = 5, list2Length = 4;
//
//   // list1
//   for (int i = 0; i < list1Length; i++){
//     int rnd = rand() % 31;
//     if (i != 0){
//       list1.insert(rnd, p);
//       p = p->next;
//     }
//     else{
//       list1.insert(rnd, list1.zeroth());
//       p = list1.first();
//     }
//   }
//
//   // list2Length
//   for (int i = 0; i < list2Length; i++){
//     int rnd = rand()/7 % 31;
//     if (i != 0){
//       list2.insert(rnd, p);
//       p = p->next;
//     }
//     else{
//       list2.insert(rnd, list2.zeroth());
//       p = list2.first();
//     }
//   }
//
//   cout << "printing original list1:" << endl;
//   list1.print();
//   cout << "printing original list2:" << endl;
//   list2.print();
//
//   return 0;
// }
