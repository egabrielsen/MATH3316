#include <iostream>
#include <cmath>
#include "fcn.hpp"

 using namespace std;

 double newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates) {
   if (show_iterates) {
     /* At each iteration, if show iterates is “true” have your
        method output the current iteration index, the current solution guess, x, the absolute value of
        the solution update, |h|, and the absolute value of the current residual, |f(x)|. */
        cout << "test" << x << endl;
   }
 }
