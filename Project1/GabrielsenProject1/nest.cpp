#include <iostream>

using namespace std;

double nest(Matrix &a, double x) {
  // a is the coefficient matrix, x is the value passed in,
  int size = a.Size();
  double p = a(size - 1);
  for (int i = (size - 2) ; i >= 0; i--) {
    p = a(i) + (x * p);
  }
  return p;
}
