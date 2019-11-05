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
  class List1{
  private:
    Node<T> *head;
  public:
    List1() : head(NULL){};
    bool isEmpty() const{return head == NULL;}
    Node<T>* first(){return head;};

    // For insertion
    // 1-define a new node
    // 2-make it point the node pointed by previous node
    // 3-make previous node to point new node.
    void insert(const T& data, Node<T>* p){
      if (p != NULL){ //case 1
        Node<T>* newNode = new Node<T>(data, p->next);
        p->next = newNode;
      }
      else{ // case 2
        Node<T>* newNode = new Node<T>(data, head);
        head = newNode;
      }
    }
  };

template <class T>
  class List2{
  private:
    Node<T>* dummyHead;
  public:
    List2(){dummyHead = new Node<T>(T(), NULL);}

    Node<T>* zeroth(){return dummyHead;}

    Node<T>* first(){return dummyHead->next;}

    bool isEmpty(){return first->next == NULL;}

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
  };

int main(int argc, char const *argv[]) {

  cout<< "Hello to linked lists!\n";

  return 0;
}
