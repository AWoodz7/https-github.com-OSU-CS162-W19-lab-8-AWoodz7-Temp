#include "matrix.hpp"
#include <iostream>

template<class T>
void printMatrix(Matrix<T>& matrix) {
  for (int k = 0; k < matrix.rows(); k++) {
    for (int j = 0; j < matrix.cols(); j++) {
      std::cout << matrix.at(k,j) << "\t";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

template<class T>
void fillMatrix(Matrix<T>& matrix, T start) {
  for (int k = 0; k < matrix.rows(); k++) {
    for (int j = 0; j < matrix.cols(); j++) {
      matrix.at(k,j) = start;
    }
  }
}

int main() {
  Matrix<int> A(3,3);
  Matrix<int> B(3,3);

  fillMatrix(A,2);
  fillMatrix(B,6);

  //std::cout << "integer matrix" << std::endl;
  printMatrix(A);
  //std::cout << "float matrix" << std::endl;
  printMatrix(B);

  try {
    A.add(B);
  } catch(size_mismatch& myException) {
    std::cerr << myException.what() << std::endl;
    return 0;
  }

  printMatrix(A);

}
