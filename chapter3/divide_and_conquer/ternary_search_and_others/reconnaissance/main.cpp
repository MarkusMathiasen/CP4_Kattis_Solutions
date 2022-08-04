#include <bits/stdc++.h>
using namespace std;
const double prec = 1e-6;

int n;
vector<int> x, v;

double range(double t) {
	double left = 1e12, right = -1e12;
	for (int i = 0; i < n; i++)
		left = min(left, x[i]+v[i]*t),
		right = max(right, x[i]+v[i]*t);
	return right-left;
}

int main() {
	scanf("%d", &n);
	x.assign(n, 0);
	v.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &x[i], &v[i]);
	double low = 0, high = 1e6;
	while (low + prec < high && low * (1 + prec-6) < high) {
		double d = (high - low)/3;
		if (range(low+d) < range(high-d))
			high -= d;
		else
			low += d;
	}
	printf("%lf\n", range(low));
}
