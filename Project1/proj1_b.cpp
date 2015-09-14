#include <iostream>
#include <vector>
#include <cmath>
#include "matrix_class/matrix.cpp"

using namespace std;

int main() {
  // -- initialize matrices
  Matrix n = Linspace(0, 52, 53, 1);;
  Matrix h(53, 1);
  Matrix r(53, 1);
  Matrix R(53, 1);

  n.Write("n.txt");

  for(int i = 0; i < n.Size(); i++) {
    h(i) = pow(2, -(n(i)));
  }
  h.Write("h.txt");

  // -- find R
  double c1 = 0.666667;
  double c2 = 1;
  for(int i = 0; i < h.Size(); i++) {
    R(i) = (c1 * h(i)) + (1 / h(i));
  }
  R.Write("R.txt");

  // -- find r
  for(int i = 0; i < r.Size(); i++) {
    double x = 3 + h(i);
    double denominator = pow(x, 3);
    denominator *= h(i);
    r(i) = .3333333 + (9/(denominator));
  }
  r.Write("r_.txt");
}
