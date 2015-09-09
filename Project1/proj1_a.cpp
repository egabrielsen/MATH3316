#include <iostream>
#include <vector>
#include "matrix_class/matrix.cpp"
#include "nest.cpp"

using namespace std;
void computeF(Matrix &z);
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
	Matrix p4(601, 1);
	Matrix p8(601, 1);
	Matrix p12(601, 1);

	// -- Creating p4, p8, and p12 matrices
	for(int i = 0; i < z.Size(); i++) {
		p4(i) = nest(p4coeff, z(i));
	}
	p4.Write("p4.txt");

	for(int i = 0; i < z.Size(); i++) {
		p8(i) = nest(p8coeff, z(i));
	}
	p8.Write("p8.txt");

	for(int i = 0; i < z.Size(); i++) {
		p12(i) = nest(p12coeff, z(i));
	}
	p12.Write("p12.txt");
	computeF(z);

	return 0;
}

void computeF(Matrix &z) {
	Matrix f(601, 1);
	for(int i = 0; i < f.Size(); i++) {
		f(i) = cos(z(i));
	}
	f.Write("f.txt");
}

double factorial(double x, double result = 1) {
  if (x == 1) return result; else return factorial(x - 1, x * result);
}
