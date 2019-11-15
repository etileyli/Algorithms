#include <iostream>
#include "llServices.h"
using namespace std;

#define MAX_LENGTH_OF_LISTS 40  // Maximum length of a list
#define MAX_VAL 31              //

int main(int argc, char const *argv[]) {
  cout << "hw2\n";

  List<int> list1, list2;
  Node<int>* p;

  int list1Length, list2Length;
  list1Length = rand() % (MAX_LENGTH_OF_LISTS);
  list2Length = rand() % (MAX_LENGTH_OF_LISTS);

  // initialize list1
  for (int i = 0; i < list1Length; i++){
    int rnd = rand() % MAX_VAL;
    if (i != 0){
      list1.insert(rnd, p);
      p = p->next;
    }
    else{
      list1.insert(rnd, list1.zeroth());
      p = list1.first();
    }
  }

  // initialize list2
  for (int i = 0; i < list2Length; i++){
    int rnd = rand()/7 % MAX_VAL;
    if (i != 0){
      list2.insert(rnd, p);
      p = p->next;
    }
    else{
      list2.insert(rnd, list2.zeroth());
      p = list2.first();
    }
  }

  list1.selectionSort();
  list2.selectionSort();

  cout << "printing new list1:" << endl;
  list1.print();

  cout << "printing new list2:" << endl;
  list2.print();

  list1.appendList(list2);
  cout << "printing appended list:" << endl;
  list1.print();

  // first sort the list to find duplicate easily
  list1.selectionSort();
  list1.print();
  cout << "Count of duplicate items: " << list1.dupItemCount() << endl;

  return 0;
}
