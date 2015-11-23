/* Erik Gabrielsen
    MATH 3316
    Project 4 */

#include <iostream>
#include <cmath>
#include "fcn.hpp"


using namespace std;

const double x1 = -.774596669241483; //to avoid calling the sqrt function
const double x2 = 0.0;
const double x3 = .774596669241483;
const double w1 = 5.0/9.0;
const double w2 = 8.0/9.0;
const double w3 = 5.0/9.0;

double composite_int(Fcn& f, const double a, const double b, const int n) {
  double h = (b - a) / n;

  double total = 0;

  double xmid, node_1, node_2, node_3;
  for (int i=0; i < n; i++) {
    xmid = a + (i+0.5)*h;
    node_1 = xmid + 0.5 * h * x1;
    node_2 = xmid + 0.5 * h * x2;
    node_3 = xmid + 0.5 * h * x3;

    total += 0.5 * h * (w1* f(node_1) + w2 * f(node_2) + w3 * f(node_3));
  }
  return total;
}
