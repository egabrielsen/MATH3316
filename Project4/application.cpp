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

  // using bisection to solve for the roots of the above function.
  // I chose the interval [800, 1100]
  double temperature = bisection(f, 800, 1100, 100, 1e-6, true);

  cout << "\nTemperature required to get carbon at a concentration of 0.006 at t = 36 hours with a depth of 3.0mm: " << endl;
  cout << "\t" << temperature << " Kelvin" << endl;

  return 0;
}
