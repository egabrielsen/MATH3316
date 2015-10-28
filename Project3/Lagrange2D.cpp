/* Erik Gabrielsen
   MATH 3316
   Program 3 */
#include <iostream>
#include <cmath>
#include "matrix.hpp"

using namespace std;

double Lagrange_basis(Matrix& x, int i, double z);
double Lagrange(Matrix& x, Matrix& y, double z);

double Lagrange2D(Matrix& x, Matrix& y, Matrix& f, double a, double b) {
  double total = 0;
  for (int i = 0; i < x.Size(); i++) {
    for (int j = 0; j < y.Size(); j++) {
      total += f(i, j) * Lagrange_basis(x, i, a) * Lagrange_basis(y, j, b);
    }
  }
  return total;
}
