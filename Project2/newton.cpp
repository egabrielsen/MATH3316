#include <iostream>
#include <cmath>
#include "fcn.hpp"

 using namespace std;

 double newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates) {
   cout << "guess " << x << " tol: " << tol << endl;
   double residual = x;
   double previous = x;
   for(int i = 0; i < maxit; i++) {
     previous = residual;
     residual = residual - f(residual)/df(residual);
     double solutionUpdate = abs(residual - previous);
     if (show_iterates) {
       /* At each iteration, if show iterates is “true” have your
          method output the current iteration index, the current solution guess, x, the absolute value of
          the solution update, |h|, and the absolute value of the current residual, |f(x)|. */
          cout << "iter " << i << "; guess " << residual << "; solution update " << solutionUpdate << "; residual: " << abs(f(residual)) << endl;
     }
     if (solutionUpdate <= tol) {
       break;
     }
   }
   cout << endl;
   return residual;
 }
