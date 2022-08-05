#include <bits/stdc++.h>
using namespace std;
const double eps = 0;

struct interval {
	double l, r;
};
interval vals[10000];

int main() {
	int n, l, w;
	while (scanf("%d%d%d", &n, &l, &w) != EOF) {
		for (int i = 0; i < n; i++) {
			int x, r; scanf("%d%d", &x, &r);
			double dx = sqrt(r*r - w*w/4.0);
			vals[i].l = x-dx;
			vals[i].r = x+dx;
			if (2*r < w)
				vals[i].l = vals[i].r = x;
		}
		sort(vals, vals+n, [](const interval& a, const interval& b) {
			if (fabs(a.l - b.l) > eps)
				return a.l < b.l;
			return a.r > b.r;
		});
		double covered = 0;
		bool possible = true;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (covered > l) break;
			if (vals[i].r < covered+eps) continue;
			if (vals[i].l < covered + eps) {
				double maxr = -1;
				for (; i < n && vals[i].l < covered + eps; i++)
					maxr = max(maxr, vals[i].r);
				i--;
				covered = maxr;
				res++;
			}
			else {
				possible = false;
				break;
			}
		}
		if (covered+eps < l || !possible)
			res = -1;
		printf("%d\n", res);
	}
}
