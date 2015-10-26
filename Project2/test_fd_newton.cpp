#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "fcn.hpp"
#include "fd_newton.cpp"

using namespace std;

// -- f(x)
class fcn : public Fcn {
public:
  double operator()(double x) {
    // f(x) = x(x - 3)(x + 1)
    return x * (x-3) * (x+1);
  }
};

int main(int argc, char* argv[]) {
    // setting up alpha = {2^-4, 2^-26, and 2^-50}
    double alpha[3] = { pow(2.0, -4), pow(2.0, -26), pow(2.0, -50) };
    double guess[3] = { -2, 1, 2 };  // initial guesses
    double tols[3] = { 1e-1, 1e-5, 1e-9 }; // tolerances
    double ans[27]; // array to store results and print to screen following fp_newtons output
    int maxit = 20;  // max set to 20 iterations of fp_newton

    fcn f;
    int index = 0;

    // iterate through tolerances
    for(unsigned int i = 0; i < 3; i++) {
      // iterate through the guesses
      for(unsigned int j = 0; j < 3; j++) {
        // iterate through alpha
        for (int k = 0; k < 3; k++) {
          ans[index] = fd_newton(f, guess[j], maxit, tols[i], alpha[k], true);
          index++;
        }
      }
    }

    // -- output all approximation answers
    for (int i =0; i < 27; i++) {
      cout << "ANS-> " << ans[i] << endl;
    }
    return 0;
}
