#include "matrix.h"
#include "time.h"
#include "vector.h"
#include <iostream>

int main() {
  // 1
  Time time;
  //time.print12();
  //time.print24();
  Time time2(16, 18, 3);
  Time time1(16, 18, 3);
  time1.print24();
  time2.print12();
  std::cout << "min time2: " << time2.getMin() << std::endl;
  // 2
  Vector A(5, 2);                       // arr[5] = {2,2,2,2,2}
  std::cout << "A: " << A << std::endl; // printing A (2,2,2,2,2)
  Vector B(A);                          // copy of A
  Vector C(4, 3);                       // arr[4] = {3,3,3,3}
  std::cout << "B: " << B << std::endl;
  std::cout << "C: " << C << std::endl;
  std::cout << "sum A + C: " << A + C << std::endl;
  std::cout << "is A==B: " << (A == B) << std::endl;
  std::cout << "is A > C: " << (A > C) << std::endl;
  std::cout << "is C < B: " << (C < B) << std::endl;
  std::cout << "is A != C: " << (A != C) << std::endl;
  std::cout << "C - B: " << C - B << std::endl;
  std::cout << "B*3: " << B * 3 << std::endl;
  std::cout << "A.changeElemInPos(2,10)" << std::endl;
  A.changeElemInPos(2, 10);
  std::cout << "Changed A: " << A << std::endl;
  std::cout << "A at pos 2: ";
  A.printElemInPos(2);
  std::cout << std::endl;
  // 3
  matrix Amat(2, 2, 5);
  std::cout << "A:\n" << A << std::endl;
  matrix Bmat(Amat);
  std::cout << "B:\n" << B << std::endl;
  Amat.setElem(1, 1, 2);
  std::cout << "changed A:\n" << A << std::endl;
  matrix Cmat = Amat;
  std::cout << "C:\n" << Cmat << std::endl;
  std::cout << "Objects: " << Cmat.count << std::endl;
  std::cout << "A+B:\n" << Amat + Bmat << std::endl;
  std::cout << "A-B:\n" << Amat - Bmat << std::endl;
  std::cout << "B/5:\n" << Bmat / 5 << std::endl;
  std::cout << "A/0:\n" << Amat / 0 << std::endl;
  std::cout << "A*B:\n" << Amat * Bmat << std::endl;
  std::cout << "A!=B: " << (Amat != Bmat) << std::endl;
  std::cout << "A==C: " << (Amat == Cmat) << std::endl;
  std::cout << "A>B: " << (Amat > Bmat) << std::endl;
  std::cout << "A<B: " << (Amat < Bmat) << std::endl;
}

