#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "fcn.hpp"
#include "newton.cpp"

using namespace std;

class fcn : public Fcn {
public:
  double operator()(double x) {   // function evaluation
    return x * (x-3) * (x+1);
  }
};

int main(int argc, char* argv[]) {
    int guesses[3] = { -2, 1, 2 };
    double tols[3] = { 10e-1, 10e-5, 10e-9 };
    int maxit = 15;

    fcn f;
    fcn df;

    for(unsigned int i = 0; i < 3; i++) {
        for(unsigned int j = 0; j < 3; j++) {
            int guess = guesses[i];
            double tol = tols[j];
            double res = newton(f, df, guess, maxit, tol, true);
        }
    }
    return 0;
}
