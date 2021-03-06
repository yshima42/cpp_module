#ifndef INCLUDE_GUARD_ARRAY_HPP
#define INCLUDE_GUARD_ARRAY_HPP

#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
 public:
  Array(unsigned int n = 0);
  virtual ~Array();
  Array(const Array &other);
  Array &operator=(const Array &other);
  T &operator[](unsigned int);
  const T &operator[](unsigned int) const;
  unsigned int size() const;

 private:
  T *_array;
  unsigned int _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &ost, const Array<T> &rhs);

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::~Array() {
  delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
  if (this != &other) {
    delete[] this->_array;
    this->_size = other._size;
    this->_array = new T[this->_size];
    for (unsigned int i = 0; i < this->_size; i++) {
      this->_array[i] = other._array[i];
    }
  }
  return *this;
}

template <typename T>
Array<T>::Array(const Array &other) : _array(NULL) {
  *this = other;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
  if (i >= _size) {
    throw std::out_of_range("Error: index out of range");
  }
  return _array[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const {
  if (i >= _size) {
    throw std::out_of_range("Error: index out of range");
  }
  return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
  return _size;
}

template <typename T>
std::ostream &operator<<(std::ostream &ost, const Array<T> &rhs) {
  ost << "{";
  for (unsigned int i = 0; i < rhs.size(); i++) {
    if (0 < i) {
      ost << ", ";
    }
    ost << rhs[i];
  }
  ost << "}";
  return ost;
}

#endif
