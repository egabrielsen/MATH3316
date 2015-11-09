#include <iostream>
#include <cmath>

#include "matrix.hpp"

double Lagrange2D(Matrix& x, Matrix& y, Matrix& f, double a, double b);
// two-dimensional Runge function
double f(double x, double y) {
    return 1.0/(1.0 + x*x + y*y);
}

// used to reuse code for 8 and 16 nodes
void computeWithNodes(unsigned int n, unsigned int m, std::string filename) {
    Matrix x = Linspace(-4, 4, m+1);
    Matrix y = Linspace(-4, 4, n+1);

    Matrix f_eval(m+1, n+1);
    for(unsigned int i = 0; i < m; i++) {
        for(unsigned int j = 0; j < n; j++) {
            // evaluate f(x, y) at all the nodes
            f_eval(i, j) = f(x(i), y(j));
        }
    }

    Matrix avals = Linspace(-4, 4, 101);
    Matrix bvals = Linspace(-4, 4, 201);

    Matrix p(101, 201);
    for(unsigned int i = 0; i < avals.Size(); i++) {
        for(unsigned int j = 0; j < bvals.Size(); j++) {
            // evaluate the 2D Lagrange polynomial at all points in avals and bvals
            p(i, j) = Lagrange2D(x, y, f_eval, avals(i), bvals(j));
        }
    }

    avals.Write("avals.txt");
    bvals.Write("bvals.txt");
    p.Write(filename.c_str());
}

int main() {
    computeWithNodes(6, 6, "p6_uni.txt");
    computeWithNodes(24, 24, "p24_uni.txt");

    Matrix avals = Linspace(-4, 4, 101);
    Matrix bvals = Linspace(-4, 4, 201);

    Matrix runge(101, 201);
    for(unsigned int i = 0; i < avals.Size(); i++) {
        for(unsigned int j = 0; j < bvals.Size(); j++) {
            // get all of the actual f values for comparison to our interpolated points
            runge(i, j) = f(avals(i), bvals(j));
        }
    }

    runge.Write("Runge.txt");
    return 0;
}
