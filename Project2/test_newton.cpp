#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "fcn.hpp"
#include "newton.cpp"

using namespace std;

// -- f(x)
class fcn : public Fcn {
public:
  double operator()(double x) {
    return x * (x-3) * (x+1);
  }
};

// -- f'(x)
class fdx : public Fcn {
public:
  double operator()(double x) {
    return ((3*x*x) - 4*x - 3);
  }
};

int main(int argc, char* argv[]) {
    double guesses[3] = { -2, 1, 2 };
    double tols[3] = { 10e-1, 10e-5, 10e-9 };
    double ans[9];
    int maxit = 15;

    fcn f;
    fdx df;
    int index = 0;

    for(unsigned int i = 0; i < 3; i++) {
        for(unsigned int j = 0; j < 3; j++) {
            double guess = guesses[i];
            double tol = tols[j];
            ans[index] = newton(f, df, guess, maxit, tol, true);
            cout << "The Approximate Root is --->  " << ans[index] << "\n" << endl;
            index++;
        }
    }

    for (int i =0; i < 9; i++) {
      cout << "ANS-> " << ans[i] << endl;
    }
    return 0;
}
