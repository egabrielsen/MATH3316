#include <iostream>
#include <vector>
#include <cmath>
#include "matrix_class/matrix.cpp"

using namespace std;

int main() {
  // -- initialize matrices
  Matrix n = Linspace(0, 52, 53, 1);;
  Matrix h(53, 1);
  Matrix R(53, 1);

  n.Write("n.txt");

  for(int i = 0; i < n.Size(); i++) {
    h(i) = pow(2, -(n(i)));
  }
  h.Write("h.txt");

  double c1 = -0.666667;
  double c2 = -1;
  for (int i = 0; i < h.Size(); i++) {
    R(i) = (c1 * h(i)) + (c2 / h(i));
  }
  R.Write("R.txt");
}
