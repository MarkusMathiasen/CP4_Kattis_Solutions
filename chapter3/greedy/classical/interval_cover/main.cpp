#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;

struct interval {
	double l, r;
	int idx;
};
bool operator<(const interval& a, const interval& b) {
	if (abs(a.l-b.l) > eps)
		return a.l < b.l;
	return a.r < b.r;
}

double A, B;
int n;
interval vals[20000];
vector<int> res;

bool solve() {
	int i = 0;
	while (i < n) {
		double max_r = -1e300;
		int max_i = -1;
		for (; i < n && vals[i].l < A + eps; i++)
			if (vals[i].r > max_r)
				max_r = vals[i].r,
				max_i = i;
		if (max_i == -1) return false;
		res.push_back(vals[max_i].idx);
		A = max_r;
		if (A + eps > B) return true;
	}
	return false;
}

int main() {
	while (scanf("%lf%lf", &A, &B) != EOF) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &vals[i].l, &vals[i].r),
			vals[i].idx = i;
		sort(vals, vals+n);
		res = {};
		if (solve()) {
			printf("%ld\n", res.size());
			for (int x : res)
				printf("%d ", x);
			printf("\n");
		}
		else
			printf("impossible\n");
	}
}
