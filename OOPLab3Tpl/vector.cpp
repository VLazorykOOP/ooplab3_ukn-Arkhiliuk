#include "vector.h"
#include <iostream>
#include <math.h>

Vector::Vector() {
  arr = new float[1];
  arr[0] = 0;
  stan = 0;
  N = 1;
}

Vector::~Vector() {
  if (arr)
    delete[] arr;
}

Vector::Vector(int N_) {
  if (N_ <= 0) {
    arr = NULL;
    N = 0;
    stan = -1;
    std::cout << "Error. N <=0. Stan is -1." << std::endl;
  } else {
    arr = new float[N_];
    for (int i = 0; i < N_; i++) {
      arr[i] = 0;
    }
    stan = 0;
    N = N_;
  }
}

Vector::Vector(int N_, float znach) {
  if (N_ <= 0) {
    arr = NULL;
    N = 0;
    stan = -1;
    std::cout << "Error. N <=0. Stan is -1." << std::endl;
  } else {
    arr = new float[N_];
    for (int i = 0; i < N_; i++) {
      arr[i] = znach;
    }
    stan = 0;
    N = N_;
  }
}

Vector::Vector(const Vector &input) {
  if (this != &input) {
    N = input.N;
    arr = new float[N];
    stan = 0;
    for (unsigned int i = 0; i < N; i++)
      arr[i] = input.arr[i];
  }
}

Vector &Vector::operator=(const Vector &vect) {
  if (N != vect.N) {
    if (arr)
      delete[] arr;
    N = vect.N;
    arr = new float[N];
    stan = 0;
  }
  for (unsigned int i = 0; i < N; i++)
    arr[i] = vect.arr[i];
  return *this;
}

void Vector::changeElemInPos(unsigned int position, float number) {
  if (arr) {
    if (position <= N) {
      arr[position] = number;
    } else
      std::cout << "Error: N > positions in array." << std::endl;
  }
}

void Vector::printElemInPos(unsigned int pos) { std::cout << arr[pos]; }

std::ostream &operator<<(std::ostream &os, const Vector &inp) {
  for (unsigned int i = 0; i < inp.N; i++) {
    os << inp.arr[i] << " ";
  }
  return os;
}

Vector Vector::operator+(const Vector &b) const {
  int resN;
  resN = N < b.N ? N : b.N;
  if (resN >= 0) {
    Vector result(resN);
    for (int i = 0; i < resN; i++) {
      result.arr[i] = arr[i] + b.arr[i];
    }
    return result;
  }
  return Vector(0);
}

Vector Vector::operator-(const Vector &b) const {
  int resN;
  resN = N < b.N ? N : b.N;
  if (resN >= 0) {
    Vector result(resN);
    for (int i = 0; i < resN; i++) {
      if (arr[i] - b.arr[i] <= 0)
        result.arr[i] = 0;
      else
        result.arr[i] = arr[i] - b.arr[i];
    }
    return result;
  }
  return Vector(0);
}

Vector Vector::operator*(unsigned int num) const {
  Vector result(N);
  for (unsigned int i = 0; i < N; i++) {
    result.arr[i] = arr[i] * num;
  }
  return result;
}

bool Vector::operator>(const Vector &b) const {
  for (unsigned int i = 0; i < N; i++) {
    if (arr[i] <= b.arr[i])
      return false;
  }
  return true;
}

bool Vector::operator<(const Vector &b) const {
  for (unsigned int i = 0; i < N; i++) {
    if (arr[i] >= b.arr[i])
      return false;
  }
  return true;
}

bool Vector::operator!=(const Vector &b) const {
  for (unsigned int i = 0; i < N; i++) {
    if (arr[i] == b.arr[i])
      return false;
  }
  return true;
}

bool Vector::operator==(const Vector &b) const {
  for (unsigned int i = 0; i < N; i++) {
    if (arr[i] != b.arr[i])
      return false;
  }
  return true;
}
