#include <iostream>
#include <vector>
#include <cmath>
#include "matrix_class/matrix.cpp"

using namespace std;

// f'(5) = (-2)*5^(-3) = -0.016

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
  double c1 = 1.33333;
  double c2 = (pow(3, -3) * pow(2, -52)) / (-3 * pow(3, -4));
  for(int i = 0; i < h.Size(); i++) {
    R(i) = abs((c1 * h(i)) + (c2 / h(i)));
  }
  R.Write("R.txt");

  // -- find r
  double fprime = -3 * pow(3, -4);
  for(int i = 0; i < r.Size(); i++) {
    double f = (pow(3, -3) - pow(3-h(i), -3)) / h(i);
    
    // errors
    r(i) = abs((fprime - f) / fprime);
  }
  r.Write("r_.txt");
}
