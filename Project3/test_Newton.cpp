/* Erik Gabrielsen
   MATH 3316
   Program 3 */

   // Inclusions
   #include <stdlib.h>
   #include <stdio.h>
   #include <iostream>
   #include <math.h>
   #include "matrix.hpp"

   using namespace std;


   // function prototypes
   Matrix Newton_coefficients(Matrix& x, Matrix& y);
   double Newton_evaluate(Matrix& x, Matrix& c, double z);
   double f(double x) {
     return cosh(2.0*x*x);
   }


   // This routine tests the function lagrange.cpp
  int main(int argc, char* argv[]) {

    vector<size_t> nvals = {10, 20};
    for (size_t k=0; k<nvals.size(); k++) {
      int n = nvals[k];
      cout << endl << "interpolants and errors using " << n+1 << " nodes:\n";

      Matrix x = Linspace(0.0, 1.0, n+1, 1);
      Matrix y(n+1);
      for(int i = 0; i <= n; i++) {
          y(i) = f(x(i));
      }
      double dx = 1.0/n;
      Matrix z = Linspace(dx/2.0, 1.0-dx/2.0, n, 1); // evaluation points

      Matrix p(n); // results of interpolation
      Matrix c(n+1); // coefficients
      c = Newton_coefficients(x, y); // only need to calculate the coefficients once
      for(int i = 0; i < n; i++) {
          // calculate Newton interpolant at each evaluation point
          p(i) = Newton_evaluate(x, c, z(i));
      }

      std::cout << "interpolant/error w/ " << n+1 << " nodes: " << std::endl;
      std::cout << "    z        f(z)               p(z)              error" << std::endl;
      for(int i = 0; i < n; i++) {
          printf("   %6.3f   %16.13f   %16.13f   %7.2g\n", z(i), f(z(i)), p(i), fabs(f(z(i)) - p(i)));
      }

    }
    return 0;
  }
