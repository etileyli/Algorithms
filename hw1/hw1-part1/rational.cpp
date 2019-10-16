#include <iostream>
#include "rational.h"

// Default (zero-argument) constructor
Rational::Rational()
{
    numer = denom = 0;
}

// Two argument constructor
Rational::Rational(int num, int den)
{
    /* TO-DO: fill the constructor */
    setNumerator(num);
    setDenominator(den);
}

void Rational::setNumerator(int num)
{
    numer = num;
}

int Rational::getNumerator()
{
    /* TO-DO */
    return numer;
}

void Rational::setDenominator(int den)
{
    /* TO-DO */
    denom = den;
}

int Rational::getDenominator()
{
    /* TO-DO */
    return denom;
}

void Rational::print()
{
    /* TO-DO */
    std::cout << "Numerator is " << numer << " and Demoniator is " << denom << "\n";
}

// Returns a + b
Rational Rational::add(Rational rhs)
{
    Rational result;

    // Simplify the result if possible. Note that we
    // are not passing "result" as an argument to
    // "simplify". Instead we are calling the "simplify"
    // function of the "result" object.

    result.simplify();

    return result;
}

// Returns a * b
Rational Rational::multiply(Rational rhs)
{
    /* TO-DO: fill multiply */
}

void Rational::simplify()
{
    /* TO-DO: fill simplify */
}

int Rational::gcd(int a, int b)
{
    int c;

    if(a<0)
        a = a * -1;
    if(b<0)
        b = b * -1;

    while (a != 0)
    {
        c = a;
        a = b % a;
        b = c;
    }

    return b;
}
