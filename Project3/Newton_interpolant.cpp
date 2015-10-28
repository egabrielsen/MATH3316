/* Erik Gabrielsen
   MATH 3316
   Program 3
   October 26th 2015*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "matrix.hpp"

using namespace std;

Matrix Newton_coefficients(Matrix& x, Matrix& y) {
  int n = y.Size() - 1;
  Matrix a(n+1);

  for (int i = 0; i < n; i++) {
    a(i) = y(i);
  }



  for (int j = 1; j < n; j++) {
    for (int i = n; i > j; i-- ) {
      a(i) = (a(i) - a(i-1))/(x(i) - x(i-j));
    }
  }
  return a;
}

double Newton_evaluate(Matrix& x, Matrix& c, double z) {
  int n = c.Size() - 1;
  double temp = c(n);
  for (int i = n-1; i > 0; i--) {
    temp *= (z - x(i));
    temp += c(i);
  }
  return temp;
}
