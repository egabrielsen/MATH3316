/* Erik Gabrielsen
    MATH 3316
    Project 4 */

#include <iostream>
#include <cmath>
#include "fcn.hpp"


using namespace std;

double composite_int(Fcn& f, const double a, const double b, const int n);

int adaptive_int(Fcn& f, const double a, const double b, const double rtol, const double atol, double& R, int& n, int& Ntot) {
    int k = 4; // initial value of k
    n = 15; // initial value of n
    double cur, next;
    next = composite_int(f, a, b, n);
    do {
        if(n >= 10000000) return 1; // convergence isn't happening fast enough or at all
        Ntot += 2*n + k; // accounts for both calculation of cur and next in this iteration
        cur = next;
        n = n + k; // increment n
        next = composite_int(f, a, b, n);
        k = n; // increase n by a proportion of itself
    } while(fabs(next-cur) >= (rtol*fabs(next) + atol)); // compares error between iterations to desired accuracy
    R = next;
    return 0;
}
