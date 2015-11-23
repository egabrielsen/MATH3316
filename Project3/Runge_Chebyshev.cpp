/* Erik Gabrielsen
   MATH 3316
   Program 3 */

#include <iostream>
#include <cmath>
#include <math.h>
#include "matrix.hpp"

using namespace std;

double Lagrange2D(Matrix& x, Matrix& y, Matrix& f, double a, double b);

// two-dimensional Runge function
double f(int x, int y) {
    return 1.0/(1 + pow(x, 2) + pow(y, 2));
}

// this method uses Chebyshev nodes in order to
// strategically place the nodes throughout the function
// x(i) = L*cos(pi*(2i + 1)/(2m+2))
double chebNode(double n, double i, double m) {
    return n*cos((2*i + 1) * M_PI / (2*m + 2));
}

// used to reuse code for 6 and 24 nodes
void interpolate(int n, int m, string filename) {
    Matrix x(m+1);
    Matrix y(n+1);
    for(int i = 0; i < x.Size(); i++) {
        // calculate all of the Chebyshev nodes
        x(i) = chebNode(4, i, m);
        y(i) = chebNode(4, i, m);
    }

    // evaluate f(x, y) at all the nodes
    Matrix f_eval(m+1, n+1);
    for(int i = 0; i < x.Size(); i++) {
        for(int j = 0; j < y.Size(); j++) {
            f_eval(i, j) = f(x(i), y(j));
        }
    }

    // interval [-4, 4]
    Matrix avals = Linspace(-4, 4, 101);
    Matrix bvals = Linspace(-4, 4, 201);

    Matrix p(101, 201); // Matrix R
    for(int i = 0; i < avals.Size(); i++) {
        for(int j = 0; j < bvals.Size(); j++) {
            // evaluate the 2D Lagrange polynomial at all points in avals and bvals
            p(i, j) = Lagrange2D(x, y, f_eval, avals(i), bvals(j));
        }
    }

    avals.Write("avals.txt");
    bvals.Write("bvals.txt");
    p.Write(filename.c_str());
}

int main() {
    interpolate(6, 6, "p6_Cheb.txt");
    interpolate(24, 24, "p24_Cheb.txt");

    return 0;
}
