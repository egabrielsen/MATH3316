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
    // f(x) = x(x-3)(x+1)
    return x * (x-3) * (x+1);
  }
};

// -- f'(x)
class fdx : public Fcn {
public:
  double operator()(double x) {
    // f'(x) = 3x^2 - 4x - 3
    return ((3*x*x) - 4*x - 3);
  }
};

int main(int argc, char* argv[]) {
    // -- set the initial guesses
    double guesses[3] = { -2, 1, 2 };

    // -- set the tolerances
    double tols[3] = { 10e-1, 10e-5, 10e-9 };
    double ans[9];
    int maxit = 15;

    fcn f; //  f(x)
    fdx df; //  f'(x)
    int index = 0;

    // -- loop through each guess
    for(unsigned int i = 0; i < 3; i++) {
      // -- inner loop: loops through each tolerance and displays the root as approximated by newtons method
        for(unsigned int j = 0; j < 3; j++) {
            double guess = guesses[i];
            double tol = tols[j];

            // -- newtons method, storing in an array for display purposes
            ans[index] = newton(f, df, guess, maxit, tol, true);

            // -- display the final approximation for tol[j] and guess[i]
            cout << "The Approximate Root is --->  " << ans[index] << "\n" << endl;
            index++;
        }
    }

    // -- ouput the approximations for each iteration of the newtons method from above in order so that
    // I can compare root guesses.
    for (int i =0; i < 9; i++) {
      cout << "ANS-> " << ans[i] << endl;
    }
    return 0;
}
