#include <iostream>
using namespace std;

void printDigit(int x){
  int y;
  cout << x % 10;
}

void printOut(int x){
  if (x >= 10)
    printOut(x/10);
  printDigit(x % 10);
}

int main(int argc, char const *argv[]) {
  /* code */
  printOut(765234);

  return 0;
}
