/* Erik Gabrielsen
   MATH 3316
   Program 3 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "martix.hpp"

using namespace std;

Matrix Newton_coefficients(Matrix& x, Matrix& y);
double Newton_evaluate(Matrix& x, Matrix& c, double z);
