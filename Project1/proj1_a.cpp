#include <iostream>
#include <vector>
#include "matrix_class/matrix.cpp"
#include "nest.cpp"

using namespace std;
void computeF(Matrix &a);

int main() {
	Matrix z = Linspace(-3.0, 3.0, 601, 1);
	double p = nest(z, 2);
	computeF(z);
	return 0;
}

void computeF(Matrix &a) {
	Matrix f = a;
	for(int i = 0; i <= 600; i++) {
		f[0][i] = cos(f[0][i]);
	}
	f.Write("f.txt");
}
