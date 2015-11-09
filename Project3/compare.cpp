/* Erik Gabrielsen
   MATH 3316
   Program 3 */
#include <iostream>
#include <cmath>
#include <chrono>
#include <stdlib.h>
#include <stdio.h>
#include "matrix.hpp"

using namespace std;

Matrix Newton_coefficients(Matrix& x, Matrix& y);
double Newton_evaluate(Matrix& x, Matrix& c, double z);
double Lagrange(Matrix& x, Matrix& y, double z);

void test_newton(int n, int m, Matrix& x, Matrix& y, Matrix& z) {
  Matrix p(m); // results of interpolation
  Matrix c(n+1); // coefficients
  c = Newton_coefficients(x, y); // only need to calculate the coefficients once
  for(int i = 0; i < m; i++) {
      // calculate Newton interpolant at each evaluation point
      p(i) = Newton_evaluate(x, c, z(i));
  }
}

void test_lagrange(int n, int m, Matrix& x, Matrix& y, Matrix& z) {
  Matrix p(m);
  for (int i = 0; i < m; i++) {
    p(i) = Lagrange(x, y, z(i));
  }
}

double f(double x) {
  return (cosh(x*x/3));
}

int main() {
  // values of n and m to use for testing.
  int n_tests[4] = {10, 20, 40, 80};
  int m_tests[4] = {100, 1000, 10000, 100000};

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int n = n_tests[i];
      int m = m_tests[j];

      Matrix x = Linspace(-2, 2, n+1);
      Matrix y(n+1);
      for (int k = 0; k < n+1; k++) {
        y(k) = f(k);
      }
      Matrix z = Linspace(-2, 2, m+1);

      chrono::time_point<std::chrono::system_clock> start, end;
      start = chrono::system_clock::now();
      // run Newton
      test_newton(n, m, x, y, z);
      end = chrono::system_clock::now();
      double newton_time = chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

      start = chrono::system_clock::now();
      // run Lagrange
      test_lagrange(n, m, x, y, z);
      end = chrono::system_clock::now();
      double lagrange_time = chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

      cout << "Time with n = " << n << " | m = " << m << endl;
      cout << "\tNewton time:        " << newton_time*1e-6 << " ms" << endl;
      cout << "\tLagrange time:      " << lagrange_time*1e-6 << " ms" << endl;
    }
  }



  return 0;
}
