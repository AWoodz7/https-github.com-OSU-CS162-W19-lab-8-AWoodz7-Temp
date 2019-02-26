#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "size_mismatch.hpp"

#include <stdexcept>
#include <iostream>

template <class T>
class Matrix {
private:
  int _rows;
  int _cols;
  T** data;
public:
  Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
    data = new T*[rows];
    for (int k = 0; k < rows; k++) {
      data[k] = new T[cols];
    }
  }

  ~Matrix() {
    for (int k = 0; k < this->_rows; k++) {
      delete[] data[k];
    }
    delete[] data;
  }

  int rows() {
    return this->_rows;
  }

  int cols() {
    return this->_cols;
  }

  T& at(int row, int col) {
    bool isInRows = (row < this->_rows && row >= 0);
    bool isInCols = (col < this->_cols && col >= 0);

    if (!isInRows || !isInCols) {
      throw std::out_of_range ("myException");
    }

    return this->data[row][col];
  }

  void add(const Matrix<T>& other) {
    if (other._rows != this->_rows || other._cols != this->_cols)
      throw size_mismatch();

    for (int k = 0; k < this->_rows; k++) {
      for (int j = 0; j < this->_cols; j++) {
        this->data[k][j] += other.data[k][j];
      }
    }
  }

};

#endif
