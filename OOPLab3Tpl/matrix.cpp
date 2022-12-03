#include "matrix.h"
#include <iostream>

int matrix::count = 0;

matrix::matrix() {
  N = 2;
  M = 2;
  arr = new float *[N];
  for (unsigned int i = 0; i < N; i++) {
    arr[i] = new float[M];
  }
  for (unsigned int i = 0; i < N; i++) {
    for (unsigned int z = 0; z < M; z++) {
      arr[i][z] = 0;
    }
  }
  stan = 0;
  count++;
}

matrix::~matrix() {
  for (unsigned int i = 0; i < N; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  count--;
}

matrix::matrix(const unsigned int N_) {
  N = N_;
  M = N_;
  arr = new float *[N];
  for (unsigned int i = 0; i < N; i++) {
    arr[i] = new float[M];
  }
  for (unsigned int i = 0; i < N; i++) {
    for (unsigned int z = 0; z < M; z++) {
      arr[i][z] = 0;
    }
  }
  stan = 0;
  count++;
}

matrix::matrix(unsigned int N_, unsigned int M_, float value) {
  N = N_;
  M = M_;
  arr = new float *[N];
  for (unsigned int i = 0; i < N; i++) {
    arr[i] = new float[M];
  }
  for (unsigned int i = 0; i < N; i++) {
    for (unsigned int z = 0; z < M; z++) {
      arr[i][z] = value;
    }
  }
  stan = 0;
  count++;
}

matrix::matrix(const matrix &input) {

  if (this != &input) {
    N = input.N;
    M = input.M;
    arr = new float *[N];
    for (unsigned int i = 0; i < N; i++) {
      arr[i] = new float[M];
    }
    for (unsigned int i = 0; i < N; i++) {
      for (unsigned int z = 0; z < M; z++) {
        arr[i][z] = input.arr[i][z];
      }
    }
  }
  stan = 0;
  count++;
}

matrix &matrix::operator=(const matrix &input) {
  if (this != &input) {
    N = input.N;
    M = input.M;
    arr = new float *[N];
    for (unsigned int i = 0; i < N; i++) {
      arr[i] = new float[M];
    }
    for (unsigned int i = 0; i < N; i++) {
      for (unsigned int z = 0; z < M; z++) {
        arr[i][z] = input.arr[i][z];
      }
    }
  }
  stan = 0;
  count++;
  return *this;
}

void matrix::setElem(unsigned int i, unsigned int j, float value) {
  arr[i][j] = value;
}

float matrix::getElem(unsigned int i, unsigned int j) { return arr[i][j]; }

matrix matrix::operator+(const matrix &b) const {
  unsigned int n = N <= b.N ? N : b.N;
  unsigned int m = M <= b.M ? M : b.M;
  matrix res(n, m, 0);
  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int z = 0; z < m; z++) {
      res.setElem(i, z, arr[i][z] + b.arr[i][z]);
    }
  }
  return res;
}

matrix matrix::operator-(const matrix &b) const {
  unsigned int n = N <= b.N ? N : b.N;
  unsigned int m = M <= b.M ? M : b.M;
  matrix res(n, m, 0);
  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int z = 0; z < m; z++) {
      res.setElem(i, z, arr[i][z] - b.arr[i][z]);
    }
  }
  return res;
}

matrix matrix::operator*(const matrix &b) const {
  if (N != b.M) {
    std::cout << "Matrices cannot be multiplied." << std::endl;
  }
  matrix res(N, b.M, 0);
  double sum = 0;
  for (unsigned int i = 0; i < N; i++) {
    for (unsigned int j = 0; j < M; j++) {
      for (unsigned int k = 0; k < b.M; k++) {
        sum += arr[i][k] * b.arr[k][j];
      }
      res.setElem(i, j, sum);
      sum = 0;
    }
  }
  return res;
}

matrix matrix::operator/(int num) const {
  matrix res(N, M, 0);
  if (num == 0) {
    std::cout << "Can't divide by 0!" << std::endl;
    return res;
  }

  for (unsigned int i = 0; i < N; i++) {
    for (unsigned int z = 0; z < M; z++) {
      res.setElem(i, z, arr[i][z] / num);
    }
  }
  return res;
}

bool matrix::operator>(const matrix &b) const {
  unsigned int n = N <= b.N ? N : b.N;
  unsigned int m = M <= b.M ? M : b.M;

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int z = 0; z < m; z++) {
      if (arr[i][z] <= b.arr[i][z]) {
        return false;
      }
    }
  }
  return true;
}

bool matrix::operator<(const matrix &b) const {
  unsigned int n = N <= b.N ? N : b.N;
  unsigned int m = M <= b.M ? M : b.M;

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int z = 0; z < m; z++) {
      if (arr[i][z] >= b.arr[i][z]) {
        return false;
      }
    }
  }
  return true;
}

bool matrix::operator!=(const matrix &b) const {
  unsigned int n = N <= b.N ? N : b.N;
  unsigned int m = M <= b.M ? M : b.M;

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int z = 0; z < m; z++) {
      if (arr[i][z] == b.arr[i][z]) {
        return false;
      }
    }
  }
  return true;
}

bool matrix::operator==(const matrix &b) const {
  unsigned int n = N <= b.N ? N : b.N;
  unsigned int m = M <= b.M ? M : b.M;

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int z = 0; z < m; z++) {
      if (arr[i][z] != b.arr[i][z]) {
        return false;
      }
    }
  }
  return true;
}

std::ostream &operator<<(std::ostream &os, const matrix &inp) {
  for (unsigned int i = 0; i < inp.N; i++, os << std::endl) {
    for (unsigned int z = 0; z < inp.M; z++) {
      os << inp.arr[i][z] << " ";
    }
  }
  return os;
}
