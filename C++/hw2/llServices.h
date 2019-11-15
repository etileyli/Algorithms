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

    void swap(Node<T>* &val1, Node<T>* val2){
      Node<T>* temp;

      insert(val1->element, val2);
      temp = val2;
      remove(val2->element);

      insert(temp->element, val1);
      remove(val1->element);
      val1 = val1->next;


      //
      // insert(val2->element, val1);
      // temp = val1;
      // val1 = val1->next;
      // remove(temp->element);
      //
      // insert(temp->element, val2);
      // cout << "val2->next->element " << val2->next->element << endl;
      // cout << "val1->element " << val1->element << endl;

      // remove(val2->element);
    }

    void selectionSort(){
      Node<T>* p = first();

      int k = 1;
      while(p->next){
        // cout << "******Cycle " << k++ << endl;
        Node<T>* minNode = p;
        Node<T>* p2 = p->next;
        // cout << "p->element = " << p->element << endl;
        // cout << "p2->element = " << p2->element << endl;
        while(p2){
          if (p2->element < minNode->element){
            // cout << "p2->element = " << p2->element << " minNode->element = " << minNode->element << endl;
            minNode = p2;
          }
          // cout << p2->element << endl;
          p2 = p2->next;
        }
        if (p->element != minNode->element){
          // cout << "Min updated to " << minNode->element << endl;
          // cout << "Swapping element " << p->element << " with element " << minNode->element << endl;
          swap(p, minNode);
        }
        // print();

        p = p->next;
        // cout << "End of cycle " << k << " p->element = " << p->element << endl;
      }
    }

    void appendList (List<T> list2){
      Node<T>* p = first();
      Node<T>* p2 = list2.first();

      while (p->next){
        p = p->next;
      }

      while (p2) {
        insert(p2->element, p);
        p2 = p2->next;
        p = p->next;
        // print();
      }
    }

    int dupItemCount(){

      int countOfDuplicates = 0;
      int temp = -1;
      Node<T>* p = first();

      while(p->next){
        if ((p->next->element == p->element)&(p->next->element != temp)){
          countOfDuplicates++;
          temp = p->element;
        }
        else
          temp = -1;

        p = p->next;
      }
      return countOfDuplicates;
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
