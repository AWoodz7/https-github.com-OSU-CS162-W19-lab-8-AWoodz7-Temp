#include "matrix.hpp"
#include <iostream>


int main() {
  Matrix<int> myIntMatrix(3,3);
  Matrix<float> myFloatMatrix(2,5);



  std::cout << "int matrix: " << myIntMatrix.at(2,2) << std::endl;


  std::cout << "float matrix: " << myFloatMatrix.at(2,2) << std::endl;

}
