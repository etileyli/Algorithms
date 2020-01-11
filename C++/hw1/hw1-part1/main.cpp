#include <iostream>
#include "rational.h"

void printAll(Rational a, Rational b, Rational c, Rational d){
  std::cout << "a => ";
  a.print();
  std::cout << "b => ";
  b.print();
  std::cout << "c = a + b => ";
  c = a.add(b);
  c.print();
  std::cout << "d = a * b => ";
  d = a.multiply(b);
  d.print();
  std::cout << std::endl;
}

int main()
{
    std::cout << "Hello Rational!" << std::endl << std::endl;

    // Test set 1
    std::cout << "Test set 1" << std::endl;
    Rational a(1, 2); // initialized by the 2-argument constructor
    Rational b(2, 4); // initialized by the 2-argument constructor
    Rational c, d;       // initialized by the 0-argument constructor
    printAll(a, b, c, d);

    // Test set 2
    std::cout << "Test set 2" << std::endl;
    Rational a2(3, 5); // initialized by the 2-argument constructor
    Rational b2(7, 11); // initialized by the 2-argument constructor
    Rational c2, d2;       // initialized by the 0-argument constructor
    printAll(a2, b2, c2, d2);

    // Test set 3
    std::cout << "Test set 3" << std::endl;
    Rational a3(5, 7); // initialized by the 2-argument constructor
    Rational b3(10, 14); // initialized by the 2-argument constructor
    Rational c3, d3;       // initialized by the 0-argument constructor
    printAll(a3, b3, c3, d3);

    // Test set 4
    std::cout << "Test set 4" << std::endl;
    Rational a4(8, 16); // initialized by the 2-argument constructor
    Rational b4(8, 32); // initialized by the 2-argument constructor
    Rational c4, d4;       // initialized by the 0-argument constructor
    printAll(a4, b4, c4, d4);

    // Test set 5
    std::cout << "Test set 5" << std::endl;
    Rational a5(17, 41); // initialized by the 2-argument constructor
    Rational b5(13, 43); // initialized by the 2-argument constructor
    Rational c5, d5;       // initialized by the 0-argument constructor
    printAll(a5, b5, c5, d5);

    return 0;
}
