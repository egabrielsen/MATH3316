#include <iostream>
#include "newton.cpp"
#include "matrix.hpp"
#include "fcn.hpp"
#include <cmath>

using namespace std;

class fcn : public Fcn {
private:
  // epsilon
  double eps = sqrt(1 - (pow(1.25, 2) / pow(2.0, 2)));
  // the initial time of t = 0;
  double t = 0;
public:
  double operator()(double x) {
    // return f(w)
    return eps * sin(x) - x - t;
  }
  void setTime(double x) {
    // update the time for each iteration
    t = x;
  }
};

// -- f'(x)
class fdx : public Fcn {
private:
  // epsilon
  double eps = sqrt(1 - (pow(1.25, 2) / pow(2.0, 2)));
public:
  double operator()(double x) {
    // f'(w)
    return eps * cos(x) - 1;
  }
};

class fr : public Fcn {
public:
  double operator()(double x) {
    // r(w)
    return .5/sqrt(pow(.5*cos(x), 2) + sin(x)*sin(x));
  }
};


int main(int argc, char* argv[]) {
  // -- Matrix of t for times.
  Matrix t = Linspace(0, 10, 10001);
  t.Write("t.txt");
  Matrix w = Matrix(10001);
  Matrix x = Matrix(10001);
  Matrix y = Matrix(10001);

  fcn f; // f(w)
  fdx df; // df(w)
  fr r; // r(w)

  for (int i = 0; i < 10001; i++) {
    double guess;
    if (i == 0) {
      guess = 0; // for first iteration guess is 0
    } else {
      guess = w(i - 1); // get the last approximation and use for the guess
    }
    f.setTime(t(i)); // update t with next time

    // -- solve for w(t)
    w(i) = newton(f, df, guess, 6, 1e-5, false);

    // -- solve the Cartesian Coordinates
    x(i) = r(w(i))*cos(w(i));
    y(i) = r(w(i))*sin(w(i));
  }
  w.Write("w.txt");
  x.Write("x.txt");
  y.Write("y.txt");


  return 0;
}
