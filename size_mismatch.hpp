#ifndef SIZE_MISMATCH_HPP
#define SIZE_MISMATCH_HPP

#include <exception>

class size_mismatch: public std::exception {
private:

public:

virtual const char* what() const throw() {
  return "The two matrices cannot be of different dimensions";
}

};
#endif
