#include <bits/stdc++.h>
using namespace std;
const double prec = 1e-8;

double dist(double x, double y, double a, double b) {
	return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		double w, g, h, r; scanf("%lf%lf%lf%lf", &w, &g, &h, &r);
		g -= r, h -= r;
		double low = 0, high = w;
		while (low + prec < high) {
			double d = (high - low)/3;
			if (dist(0, g, low+d, 0) + dist(low+d, 0, w, h) <
				dist(0, g, high-d,0) + dist(high-d,0, w, h))
				high -= d;
			else
				low += d;
		}
		printf("%lf %lf\n", dist(0, g, w, h), dist(0, g, low, 0) + dist(low, 0, w, h));
	}
}
