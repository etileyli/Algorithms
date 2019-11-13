#include <iostream>
#include "llServices.h"
using namespace std;

int main(int argc, char const *argv[]) {
  cout << "hw2\n";

    List<int> list1, list2;
    Node<int>* p;

    int list1Length = 5, list2Length = 4;

    // list1
    for (int i = 0; i < list1Length; i++){
      int rnd = rand() % 31;
      if (i != 0){
        list1.insert(rnd, p);
        p = p->next;
      }
      else{
        list1.insert(rnd, list1.zeroth());
        p = list1.first();
      }
    }

    // list2Length
    for (int i = 0; i < list2Length; i++){
      int rnd = rand()/7 % 31;
      if (i != 0){
        list2.insert(rnd, p);
        p = p->next;
      }
      else{
        list2.insert(rnd, list2.zeroth());
        p = list2.first();
      }
    }

    cout << "printing original list1:" << endl;
    list1.print();
    cout << "printing original list2:" << endl;
    list2.print();

  return 0;
}
