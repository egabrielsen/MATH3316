#include <iostream>
#include <cmath>
#include "fcn.hpp"

 using namespace std;

 double newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates) {
   if (show_iterates) {
     cout << endl;
     cout << "guess " << x << " tol: " << tol << endl;
   }

   int iteration = 0;
   double solutionUpdate = 10;

   // -- go to max iterations or until solution update is less than the tolerance
   while(iteration <= maxit && solutionUpdate > tol) {
     iteration++;
     double previous = x;

     // -- x = x(n+1) by (x - f(x)/f'(x))
     x = x - (f(x)/df(x));

     // -- solution update = |x(n+1) - x|
     solutionUpdate = fabs(x - previous);

     if (show_iterates) {
       //-- output the iteration, guess, solution update and residual for each iteration
       cout << "iter " << iteration << "; guess " << x << "; solution update " << solutionUpdate << "; residual: " << fabs(f(x)) << endl;
     }
   }
   return x;
 }
