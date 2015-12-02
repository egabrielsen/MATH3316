/* Erik Gabrielsen
  Math 3316
  27 November 2015 */

#include <iostream>
#include <cmath>
#include "fcn.hpp"
#include "matrix.hpp"

using namespace std;

double carbon(const double x, const double t, const double T, const double rtol, const double atol);

const double atolerance = 1e-11;
const double rtolerance = 1e-15;

int main() {
  Matrix K = Linspace(800, 1200, 400); // Kelvin
  Matrix t = Linspace(1, 172800, 600); // 48 hours (172800 s)
  Matrix c2mm = Matrix(400, 600);
  Matrix c4mm = Matrix(400, 600);
  Matrix C2mm_800K = Matrix(600);
  Matrix C2mm_900K = Matrix(600);
  Matrix C2mm_1000K = Matrix(600);
  Matrix C2mm_1100K = Matrix(600);
  Matrix C2mm_1200K = Matrix(600);
  Matrix C4mm_800K = Matrix(600);
  Matrix C4mm_900K = Matrix(600);
  Matrix C4mm_1000K = Matrix(600);
  Matrix C4mm_1100K = Matrix(600);
  Matrix C4mm_1200K = Matrix(600);

  for (int i = 0; i < 400; i++) {
    for (int j = 0; j< 600; j++) {
      c2mm(i, j) = carbon(.002, t(j), K(i), rtolerance, atolerance);
      c4mm(i, j) = carbon(.004, t(j), K(i), rtolerance, atolerance);
    }
  }
  for (int i = 0; i < 600; i++) {
    C2mm_800K(i) = carbon(.002, t(i), 800, rtolerance, atolerance);
    C2mm_900K(i) = carbon(.002, t(i), 900, rtolerance, atolerance);
    C2mm_1000K(i) = carbon(.002, t(i), 1000, rtolerance, atolerance);
    C2mm_1100K(i) = carbon(.002, t(i), 1100, rtolerance, atolerance);
    C2mm_1200K(i) = carbon(.002, t(i), 1200, rtolerance, atolerance);
    C4mm_800K(i) = carbon(.004, t(i), 800, rtolerance, atolerance);
    C4mm_900K(i) = carbon(.004, t(i), 900, rtolerance, atolerance);
    C4mm_1000K(i) = carbon(.004, t(i), 1000, rtolerance, atolerance);
    C4mm_1100K(i) = carbon(.004, t(i), 1100, rtolerance, atolerance);
    C4mm_1200K(i) = carbon(.004, t(i), 1200, rtolerance, atolerance);
  }

  K.Write("Temp.txt");
  t.Write("time.txt");
  c2mm.Write("c2mm.txt");
  c4mm.Write("c4mm.txt");
  C2mm_800K.Write("C2mm_800K.txt");
  C2mm_900K.Write("C2mm_900K.txt");
  C2mm_1000K.Write("C2mm_1000K.txt");
  C2mm_1100K.Write("C2mm_1100K.txt");
  C2mm_1200K.Write("C2mm_1200K.txt");
  C4mm_800K.Write("C4mm_800K.txt");
  C4mm_900K.Write("C4mm_900K.txt");
  C4mm_1000K.Write("C4mm_1000K.txt");
  C4mm_1100K.Write("C4mm_1100K.txt");
  C4mm_1200K.Write("C4mm_1200K.txt");
  return 0;
}
