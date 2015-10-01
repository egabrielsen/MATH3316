#include <iostream>
#include <cmath>

using namespace std;

double fd_newton(Fcn& f, double x, int maxit, double tol, double alpha, bool show_iterates) {
  cout << "guess " << x << " tol: " << tol << " alpha: " << alpha << endl;
  int iteration = 0;
  double solutionUpdate = 10;

  // -- go to max iterations or until solution update is less than the tolerance
  while(iteration <= maxit && solutionUpdate > tol) {
    iteration++;
    double previous = x;

    double dpF = (f(x + alpha) - f(x)) / alpha;
    // -- x = x(n+1) by (x - f(x)/f'(x))
    x = x - (f(x)/dpF);

    // -- solution update = |x(n+1) - x|
    solutionUpdate = fabs(x - previous);

    if (show_iterates) {
      //-- output the iteration, guess, solution update and residual for each iteration
      cout << "iter " << iteration << ", x = " << x << ", |h| = " << solutionUpdate << "; |f(x)| =  " << fabs(f(x)) << endl;
    }
  }
  cout << endl;
  return x;
}
