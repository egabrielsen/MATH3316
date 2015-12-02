/* Erik Gabrielsen
  MATH 3316
  30 November 2015 */

#include <iostream>
#include <cmath>
#include "fcn.hpp"

using namespace std;

const double atolerance = 1e-15;
const double rtolerance = 1e-14;
const double depth = .003;
const double t = 129600; // 36 hours
const double accuracy = 0.0001; // accurate to the .0001 K

double bisection(Fcn& f, double a, double b, int maxit, double tol, bool show_iterates);
double carbon(const double x, const double t, const double T, const double rtol, const double atol);

class fc : public Fcn {
public:
  double operator()(double T) {
    return carbon(depth, t, T, rtolerance, atolerance) - 0.006;
  }
};

int main() {
  fc f;
  // cout << solver(300);
  cout << bisection(f, 0, 1500, 100, 1e-6, true);
  
  return 0;
}
