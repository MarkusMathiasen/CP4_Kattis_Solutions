#include <bits/stdc++.h>
using namespace std;

struct seg {
	double d;
	double s;
};

int n, t; 
vector<seg> segs;

double tim(double c) {
	double res = 0;
	for (seg& x : segs)
		res += x.d / max(1e-9, x.s-c);
	return res;
}

int main() {
	scanf("%d%d", &n, &t);
	segs.assign(n, seg());
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &segs[i].d, &segs[i].s);
	double low = -1e9, high = 1e9;
	while (low + 1e-8 < high) {
		double mid = (low + high)/2;
		if (tim(mid) < t)
			low = mid; // make slower
		else
			high = mid; // make faster
	}
	printf("%lf\n", -low);
}
