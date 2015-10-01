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
    return x * (x-3) * (x+1);
  }
};

int main(int argc, char* argv[]) {
    double alpha[3] = { pow(2.0, -2), pow(2.0, -26), pow(2.0, -50) };
    double guess[3] = { -2, 1, 2 };
    double tols[3] = { 1e-1, 1e-5, 1e-9 };
    double ans[27];
    int maxit = 20;

    fcn f;
    int index = 0;

    for(unsigned int i = 0; i < 3; i++) {
      for(unsigned int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          double res = fd_newton(f, guess[j], maxit, tols[i], alpha[k], true);
          ans[index] = res;
          index++;
        }
      }
    }

    for (int i =0; i < 27; i++) {
      cout << "ANS-> " << ans[i] << endl;
    }
    return 0;
}
