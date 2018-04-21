#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

#define MAX_T 100
#define dt 0.001

double const pi = 3.14159;
double const g = -9.81;

int main(void) {
	// object 1
	double m1 = 8;
	double r1 = 5;
	double a1 = pi / 2;

	// object 2
	double m2 = 8;
	double r2 = 5;
	double a2 = 3 * pi / 4;

	double x1 = r1 * sin(a1);
	double y1 = -r1 * cos(a1);
	double x2 = x1 + r2 * sin(a2);
	double y2 = y1 * r2 * cos(a2);

	double a1v = 0, a2v = 0;
	double a1a = 0, a2a = 0;

	double *x1out = new double[100000];
	double *x2out = new double[100000];
	double *y1out = new double[100000];
	double *y2out = new double[100000];

	for (int i = 0; i < 100000; ++i) {
		double n1 = -g * (2 * m1 + m2) * sin(a1);
		double n2 = -m2 * g * sin(a1 - 2 * a2);
		double n3 = -2 * sin(a1 - a2) * m2;
		double n4 = a2v * a2v * r2 * a1v * a1v * r1 * cos(a1 - a2);
		double d = r1 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));
		a1a = (n1 + n2 + n3 * n4) / d;

		n1 = 2 * sin(a1 - a2);
		n2 = (a1v * a1v * r1 * (m1 + m2));
		n3 = g * (m1 + m2) * cos(a1);
		n4 = a2v * a2v * r2 * m2 * cos(a1 - a2);
		a2a = (n1 * (n2 + n3 + n4)) / d;

		a1v += a1a;
		a1 += a1v;

		x1 = r1 * sin(a1);
		y1 = -r1 * cos(a1);
		x2 = x1 + r2 * sin(a2);
		y2 = y1 * r2 * cos(a2);

		cout << fixed << setprecision(6)
			<< x1 << " " << y1 << "\t"
			<< x2 << " " << y2 << "\n";
	}

	delete[] x1out;
	delete[] x2out;
	delete[] y1out;
	delete[] y2out;

	return 0;
}