/* Erik Gabrielsen
  Math 3316
  27 November 2015 */

#include <iostream>
#include <cmath>
#include "fcn.hpp"

using namespace std;

const double PI = atan(1.0)*4;

// including adaptive_int
int adaptive_int(Fcn& f, const double a, const double b, const double rtol, const double atol, double& R, int& n, int& Ntot);

class fcn : public Fcn {
public:
  double operator()(double z) {   // function evaluation of e^((-z)^2)
    return exp(-(z*z));
  }
};

// -- initial values of C0
const double C0 = .001;
const double Cs = .02;

double erf(const double y, const double rtol, const double atol) {
  fcn f; // can I instead pass this as an argument to erf?
  double R;
  int n, nTot;

  if (adaptive_int(f, 0, y, rtol, atol, R, n, nTot) == 1) {
    R *= 2.0/sqrt(PI);
  }
  return R;
}

double D(const double T) {
  return 6.2e-7*exp(-8e4/(8.31*T));
}

double carbon(const double x, const double t, const double T, const double rtol, const double atol) {
  return Cs - (Cs-C0)* erf((x/sqrt(4*t*D(T))), rtol, atol);
}
