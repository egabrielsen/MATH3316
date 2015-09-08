#include <iostream>
#include <vector>
#include "matrix_class/matrix.cpp"
#include "nest.cpp"

using namespace std;
void computeF(Matrix &a);
double factorial(double x, double result);

int main() {
	// -- create Matrix z
	Matrix z = Linspace(-3.0, 3.0, 601, 1);
	z.Write("z.txt");

	// -- Coefficients 
	double p4data[] = {factorial(1, 1), factorial(2, 1), factorial(4, 1)};
	double p8data[] = {factorial(1, 1), factorial(2, 1), factorial(4, 1), factorial(6, 1), factorial(8, 1)};
	double p12data[] = {factorial(1, 1), factorial(2, 1), factorial(4, 1), factorial(6, 1),factorial(8, 1), factorial(10, 1), factorial(12, 1)};

	// -- Coefficient matrices for each polynomial
	Matrix p4coeff(1, 3, p4data);
	Matrix p8coeff(1, 5, p8data);
	Matrix p12coeff(1, 7, p12data);

	// -- Matrix for polynomials, initialized to 0
	Matrix p4(1, 600);
	Matrix p8(1, 600);
	Matrix p12(1, 600);
	cout << p4 << endl;
	cout << p8 << endl;
	cout << p12 << endl;

	// cout << nest(p[0], 4);
	// for(int i = 0; i <= 600; i++) {
	// 	p4[0][i] = nest(a, 4)
	// }
	// computeF(z);
	return 0;
}

void computeF(Matrix &a) {
	Matrix f = a;
	for(int i = 0; i <= 600; i++) {
		f[0][i] = cos(f[0][i]);
	}
	f.Write("f.txt");
}

double factorial(double x, double result = 1) {
  if (x == 1) return result; else return factorial(x - 1, x * result);
}
