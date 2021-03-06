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

  };

int main(int argc, char const *argv[]) {

  cout<< "Hello to linked lists!\n";

  List<int> list;
  list.insert(0, list.zeroth());
  Node<int>* p = list.first();

  for (int i = 1; i <= 10; i++){
    list.insert(i, p);
    p = p->next;
  }

  for (int i = 0; i <= 10; i++)
    if (i % 2 == 0)
      list.remove(i);

  cout << "printing original list:" << endl;
  list.print();

  List<int> list2 = list;
  cout << "printing copy constructed list" << endl;
  list2.print();

  List<int> list3;
  list3 = list;
  cout << "printing list 3:" << endl;
  list.print();

  list.makeEmpty();
  cout << "printing empty list:" << endl;
  list.print();

  return 0;
}
