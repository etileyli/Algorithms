#include <iostream>
#include "matrix.h"
#include <math.h>

void testFunction(int randGenVal){

  Matrix m2, m3;
  int dim = 4;
  for  (int i = 0; i < dim; i++)
    for  (int j = 0; j < dim; j++){
      m2.set_number(i, j, rand() % randGenVal);
      m3.set_number(i, j, rand() % randGenVal);
    }

  std::cout << "matrix m2: " << std::endl;
  std::cout << m2;
  std::cout << std::endl;

  std::cout << "matrix m3: " << std::endl;
  std::cout << m3;
  std::cout << std::endl;

  m2.sum_with(m3);
  std::cout << "matrix m2 = m2 + m3: " << std::endl;
  std::cout << m2;
  std::cout << std::endl;

  m2.substract(m3);
  std::cout << "matrix m2 = m2 - m3: " << std::endl;
  std::cout << m2;
  std::cout << std::endl;

  m2 = m3;
  std::cout << "m2 is now equal to m3: " << std::endl;
  std::cout << m2;
  std::cout << std::endl;

  m2.transpose();
  std::cout << "Transpose of m2: " << std::endl;
  std::cout << m2;
  std::cout << std::endl;
}

int main()
{
    // You can test your implementation here.

    std::cout << "Matrix main..." << std::endl << std::endl;
    int dimension = 5;
    Matrix m1(dimension);
    std::cout << "matrix m1: " << std::endl;
    std::cout << m1;
    std::cout << std::endl;

    // Test for 5 input sets
    for (int i = 1; i < 6; i++){
      std::cout << "**********************  Test Set " << i << "  **********************"<< std::endl;
      testFunction(6 + 2 * i);  // change random generated values
    }

    return 0;
}
