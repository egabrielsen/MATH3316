/* Erik Gabrielsen
  MATH 3316 */

#include <iostream>
#include <cmath>
#include "fcn.hpp"


using namespace std;

int adaptive_int(Fcn& f, const double a, const double b, const double rtol, const double atol, double& R, int& n, int& Ntot);

class fcn : public Fcn {
public:
  double c, d;
  double operator()(double x) {   // function evaluation
    return (exp(c*x) + sin(d*x));
  }
  double antiderivative(double x) { // function evaluation
    return (exp(c*x)/c - cos(d*x)/d);
  }
};

int main() {
    // limits of integration
    fcn f;
    const double a = -1;
    const double b = 7;
    f.c = 0.5;
    f.d = 25.0;


    // actual integral value
    double trueVal = 1.0 / f.c * (exp(f.c*b) - exp(f.c*a)) - 1.0 / f.d * (cos(f.d*b) - cos(f.d*a));
    printf("True integral value = %22.16e\n\n", trueVal);

    // test values
    double rtols[] = { 1e-2, 1e-4, 1e-6, 1e-8, 1e-10, 1e-12 };
    double atols[] = { 1e-5, 1e-7, 1e-9, 1e-11, 1e-13, 1e-15 };

    std::cout << "    rtol     atol      n    nTot        R         |I(f)-R(f)|  rtol|I(f)|+atol     Passed" << std::endl;
    for(int i = 0; i < 6; i++) { // for each pair of tols
        double R;
        int n, nTot = 0;
        int passed = adaptive_int(f, a, b, rtols[i], atols[i], R, n, nTot);
        double err = fabs(trueVal - R);
        double errBound = rtols[i] * fabs(trueVal) + atols[i];
        if (passed == 0) {
            printf("  %2.1e | %2.1e | %3u | %5u | %12.6e |  %7.1e  |   %7.1e      |      yes\n", rtols[i], atols[i], n, nTot, R, err, errBound);
        } else {
          printf("  %2.1e | %2.1e | %3u | %5u | %12.6e |  %7.1e  |   %7.1e      |       no\n", rtols[i], atols[i], n, nTot, R, err, errBound);
        }

    }
    cout << endl;
}
