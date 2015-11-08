#include <iostream>
#include <cmath>
#include <math.h>

#include "matrix.hpp"

double Lagrange2D(Matrix& x, Matrix& y, Matrix& f, double a, double b);

// two-dimensional Runge function
double f(int x, int y) {
    return 1.0/(1 + std::pow(x, 2) + std::pow(y, 2));
}

// this method uses Chebyshev nodes in order to remedy the issues
// associated with equispaced interpolation points
// x(i) = L*cos(pi*(2i + 1)/(2m+2))
double chebNode(double n, double i, double m) {
    return n*std::cos((2*i + 1) * M_PI / (2*m + 2));
}

// used to reuse code for 8 and 16 nodes
void computeWithNodes(unsigned int n, unsigned int m, std::string filename) {
    Matrix x(m+1);
    Matrix y(n+1);
    for(unsigned int i = 0; i < x.Size(); i++) {
        // calculate all of the Chebyshev nodes
        x(i) = chebNode(4, i, m);
        y(i) = chebNode(4, i, m);
    }

    // evaluate f(x, y) at all the nodes
    Matrix f_eval(m+1, n+1);
    for(unsigned int i = 0; i < x.Size(); i++) {
        for(unsigned int j = 0; j < y.Size(); j++) {
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
    computeWithNodes(6, 6, "p8_cheb.txt");
    computeWithNodes(24, 24, "p16_cheb.txt");

    return 0;
}
