#include <bits/stdc++.h>
using namespace std;
const int N = 50000;
const double prec = 1e-7;

int n;
double x[N], y[N];

double tim(double p) {
	double res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, (x[i]-p)*(x[i]-p)+y[i]*y[i]);
	return sqrt(res);
}

int main() {
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", x+i, y+i);
		double low = -200000, high = 200000;
		while (low + prec < high && low * (1+prec) < high) {
			double d = (high-low)/3;
			if (tim(low+d) < tim(high-d))
				high -= d;
			else
				low += d;
		}
		printf("%lf %lf\n", low, tim(low));
	}
}
