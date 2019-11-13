#include <iostream>
using namespace std;

class StackException {
public:
    StackException(const string& err) : error(err) {}
    string error;
};

const int MAX_STACK = 1000;

template<class T>
class Stack1{
private:
  T items[MAX_STACK];
  int top;
public:
  Stack1():top(-1){};

  //Stack operations
  bool isEmpty() const{return top < 0;};

  void push(const T& newItem){
    if (top >= MAX_STACK - 1)
      throw StackException("StackException: Stack full on push!/n");
    else
      items[++top] = newItem;
  }

  void pop(){
    if (isEmpty())
      throw StackException("StackException: Stack empty on pop!/n");
    else
      --top;
  }

  void popAndTop(T& stackTop){
    if (isEmpty())
      throw StackException("StackException: Stack empty on popAndTop!/n");
    else
      stackTop = items[top--];
  }

  void getTop(T& stackTop){
    if (isEmpty())
      throw StackException("StackException: Stack empty on getTop!/n");
    else
      stackTop = items[top];
  }
};

template <class Object>
class StackNode
{
    public:
        StackNode(const Object& e = Object(), StackNode* n = NULL)
            : item(e), next(n) {}

        Object item;
        StackNode* next;
};

template<class T>
class Stack{
public:
  Stack():topPtr(NULL){};

  ~Stack(){
    while (!isEmpty())
      pop();
  }

  bool isEmpty()const{
    return topPtr == NULL;
  }

  void push(const T& newItem){
    // create new Node
    StackNode<T> *newPtr = new StackNode<T>;
    newPtr->item = newItem; //insert the data

    newPtr->next = topPtr;  // link this node to the
    topPtr = newPtr;   // update the stack top
  }

  void pop(){
    if(isEmpty())
      throw StackException("StackException: stack empty on pop!/n");
    else{
      StackNode<T> *tmp = topPtr;
      topPtr= topPtr->next; // update the stack top
      delete tmp;
    }
  }

  void topAndPop(T& stackTop){
    if (isEmpty())
      throw StackException("StackException: stack empty on popAndTop!/n");
    else
      stackTop = topPtr->item;
      StackNode<T> *tmp = topPtr;
      topPtr = topPtr->next; // update the stack top
      delete tmp;
  }

  void getTop(T& stackTop){
    if(isEmpty())
      throw StackException("StackException: stack empty on pop!/n");
    else
      stackTop = topPtr->item;
  }

  Stack<T>& operator=(const Stack& rhs) {
    if (this != &rhs) {
        if (!rhs.topPtr)
            topPtr = NULL;
        else {
            topPtr = new StackNode<T>;
            topPtr->item = rhs.topPtr->item;
            StackNode<T>* q = rhs.topPtr->next;
            StackNode<T>* p = topPtr;
            while (q) {
                p->next = new StackNode<T>;
                p->next->item = q->item;
                p = p->next;
                q = q->next;
            }
            p->next = NULL;
        }
    }
    return *this;
}

Stack<T> (const Stack& rhs) {
    *this = rhs; // reuse assignment operator
}

private:
  StackNode<T> *topPtr;
};

int main(int argc, char const *argv[]) {

  cout<< "Hello from stacks!\n";

  Stack<int> s;
  for (int i = 0; i < 10; i++)
      s.push(i);

  Stack<int> s2 = s; // test copy constructor (also tests assignment)

  cout << "Printing s:" << endl;
  while (!s.isEmpty()) {
      int value;
      s.topAndPop(value);
      cout << value << endl;
  }

  cout << "Printing s2:" << endl;
  while (!s2.isEmpty()) {
      int value;
      s2.topAndPop(value);
      cout << value << endl;
  }

  return 0;
}
