#include <iostream>
#include "newton.cpp"
#include "matrix.hpp"
#include "fcn.hpp"
#include <cmath>

using namespace std;

class fcn : public Fcn {
public:
  double operator()(double x) {
    double eps = 0.780624749;
    return eps * sin(x) - x;
  }
};

// -- f'(x)
class fdx : public Fcn {
public:
  double operator()(double x) {
    double eps = 0.780624749;
    return eps * cos(x) - 1;
  }
};

class fr : public Fcn {
public:
  double operator()(double x) {
    return .5/sqrt(pow(.5*cos(x), 2) + sin(x)*sin(x));
  }
};


int main(int argc, char* argv[]) {
  double a = 2.0;
  double b = 1.25;
  // epsilon =
  double epsilon = sqrt(1 - (pow(a, 2) / pow(b, 2)));
  Matrix t = Linspace(0, 10, 10001);
  t.Write("t.txt");
  Matrix w = Matrix(10001);
  Matrix x = Matrix(10001);
  Matrix y = Matrix(10001);

  fcn f;
  fdx df;
  fr r;

  for (int i = 0; i < 10; i++) {
    double guess;
    if (i == 0) {
      guess = 0;
    } else {
      guess = w(i - 1);
    }
    w(i) = newton(f, df, guess, 6, 1e-5, true);
    x(i) = r(w(i))*cos(w(i));
    y(i) = r(w(i))*sin(w(i));
  }
  w.Write("t.txt");
  x.Write("x.txt");
  y.Write("y.txt");


  return 0;
}
