#include <iostream>
#include <vector>
#include <cmath>
#include "matrix_class/matrix.cpp"
#include "nest.cpp"

using namespace std;
double factorial(double x, double result);

int main() {
	// -- create Matrix z
	Matrix z = Linspace(-3.0, 3.0, 601, 1);
	z.Write("z.txt");

	// -- Coefficients
	double p4data[] = {1, 0, (-1/factorial(2, 1)), 0, (1/factorial(4, 1))};
	double p8data[] = {1, 0, (-1/factorial(2, 1)), 0, (1/factorial(4, 1)), 0, (-1/factorial(6, 1)), 0, (1/factorial(8, 1))};
	double p12data[] = {1, 0, (-1/factorial(2, 1)), 0, (1/factorial(4, 1)), 0, (-1/factorial(6, 1)), 0, (1/factorial(8, 1)), 0, (-1/factorial(10, 1)), 0, (1/factorial(12, 1))};

	// -- Coefficient matrices for each polynomial
	Matrix p4coeff(5, 1, p4data);
	Matrix p8coeff(9, 1, p8data);
	Matrix p12coeff(13, 1, p12data);

	// -- Matrix for polynomials, initialized to 0
	Matrix f(601, 1);
	Matrix p4(601, 1);
	Matrix p8(601, 1);
	Matrix p12(601, 1);
	Matrix err4(601, 1);
	Matrix err8(601, 1);
	Matrix err12(601, 1);

	// -- Creating f, p4, p8, p12, err4, err8, err12
	for(int i = 0; i < z.Size(); i++) {
		f(i) = cos(z(i));
		p4(i) = nest(p4coeff, z(i));
		p8(i) = nest(p8coeff, z(i));
		p12(i) = nest(p12coeff, z(i));
		err4(i) = abs(f(i) - p4(i));
		err8(i) = abs(f(i) - p8(i));
		err12(i) = abs(f(i) - p12(i));
	}
	
	// -- Writing Out files
	f.Write("f.txt");
	p4.Write("p4.txt");
	p8.Write("p8.txt");
	p12.Write("p12.txt");
	err4.Write("err4.txt");
	err8.Write("err8.txt");
	err12.Write("err12.txt");

	return 0;
}

double factorial(double x, double result = 1) {
  if (x == 1) return result; else return factorial(x - 1, x * result);
}
