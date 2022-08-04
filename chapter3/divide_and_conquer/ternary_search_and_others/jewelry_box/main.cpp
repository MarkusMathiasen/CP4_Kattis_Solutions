#include <bits/stdc++.h>
using namespace std;

int T, X, Y;

double volume(double h) {
	double a = X - 2*h;
	double b = Y - 2*h;
	return a * b * h;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &X, &Y);
		double low = 0, high = min(X, Y)/2.0;
		while (low + 1e-8 < high && low * (1 + 1e-8) < high) {
			double d = (high - low)/3;
			if (volume(low + d) < volume(high - d))
				low += d;
			else
				high -= d;
		}
		printf("%lf\n", volume(low));
	}
}
