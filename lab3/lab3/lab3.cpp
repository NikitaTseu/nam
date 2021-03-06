#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

#define PI 3.14159265359

using namespace std;

double A = 0;
double B = 1;

double eps = 0.000001;

ofstream fout("output.txt");

double f(double x) {
	return sin(2 * x) + 3 * x;
}

double integrate(int n) {
	double integral = 0;
	double h = (B - A) / n;
	for (int i = 0; i < n; i++) {
		double a = A + i * h;
		double b = a + h;
		integral += (h / 2.0)*(f(a) + f(b));
	}
	fout << "I_" << n << " = " << setprecision(8) << integral << endl;
	return integral;
}

int main()
{
	int n = 1;
	double prev = -1000000000;
	double cur = integrate(1);

	while (fabs(cur - prev) > eps) {
		prev = cur;
		n*=2;
		cur = integrate(n);
	}
	return 0;
}

