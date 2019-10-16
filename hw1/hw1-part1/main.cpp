#include <iostream>
#include "rational.h"

int main()
{
    std::cout << "Hello Rational!" << std::endl;

    Rational a(1, 2); // initialized by the 2-argument constructor
    Rational b(2, 4); // initialized by the 2-argument constructor
    Rational c, d;       // initialized by the 0-argument constructor

    c = a.add(b);
    d = a.multiply(b);
    //
    // a.print();
    // b.print();
    c.print();
    d.print();

    return 0;
}
