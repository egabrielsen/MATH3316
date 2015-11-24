/* Erik Gabrielsen
    MATH 3316
    Project 4 */

#include <iostream>
#include <cmath>
#include "fcn.hpp"


using namespace std;

const double x1 = -0.8611363116; //to avoid calling the sqrt function
const double x2 = -0.3399810436;
const double x3 = 0.3399810436;
const double x4 = 0.8611363116;
const double w1 = 0.3478548451;
const double w2 = 0.6521451549;
const double w3 = 0.6521451549;
const double w4 = 0.3478548451;

double composite_int(Fcn& f, const double a, const double b, const int n) {
  double h = (b - a) / n;

  double total = 0;

  double xmid, node_1, node_2, node_3, node_4;
  for (int i=0; i < n; i++) {
    xmid = a + (i+0.5)*h;
    node_1 = xmid + 0.5 * h * x1;
    node_2 = xmid + 0.5 * h * x2;
    node_3 = xmid + 0.5 * h * x3;
    node_4 = xmid + 0.5 * h * x4;

    total += 0.5 * h * (w1* f(node_1) + w2 * f(node_2) + w3 * f(node_3) + w4 * f(node_4));
  }
  return total;
}
