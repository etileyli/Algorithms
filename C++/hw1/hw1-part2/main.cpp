#include <iostream>
#include "matrix.h"
#include <math.h>

int main()
{
    // You can test your implementation here.

    std::cout << "Matrix main..." << std::endl;
    int dimension = 5;
    Matrix m1(dimension);
    std::cout << m1;

    // Test for set_number function
    for  (int i = 0, k = 0; i < dimension; i++)
      for  (int j = 0; j < dimension; j++, k++)
        m1.set_number(i, j, k);

    std::cout << m1;

    // Test for sum_with function
    Matrix m2, m3;
    int dim = 4;
    for  (int i = 0; i < dim; i++)
      for  (int j = 0; j < dim; j++){
        m2.set_number(i, j, rand() % 10);
        m3.set_number(i, j, rand() % 10);
      }

    std::cout << "matrix 2: " << std::endl;
    std::cout << m2;
    std::cout << "matrix 3: " << std::endl;
    std::cout << m3;

    m2.sum_with(m3);
    std::cout << "matrix SUM: " << std::endl;
    std::cout << m2;

    m2.substract(m3);
    std::cout << "matrix SUBSTRACT: " << std::endl;
    std::cout << m2;

    return 0;
}
