#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> dd;

int w, h, n;
double ah;
vector<dd> dp;

double right_cost(double pos) {
	double d = pos*ah + 1-pos + ah;
	double res = d*d/4;
	return res - pos*ah * pos*ah / 2;
}

int main() {
	scanf("%d%d%d", &w, &h, &n);
	ah = h/(double)w;
	dp.assign(n+1, dd(0, 0));
	dp[0] = dd(0, (1+ah)*(1+ah)/4);
	for (int i = 1; i <= n; i++) {
		double low = 0, high = 1;
		while (low + 1e-8 < high && low * (1+1e-8) < high) { // Is this precise enough?
			double d = (high - low)/3;
			double p1 = low+d;
			double p2 = high-d;
			double c1 = right_cost(p1) + dp[i-1].second*p1*p1;
			double c2 = right_cost(p2) + dp[i-1].second*p2*p2;
			if (c1 < c2)
				high -= d;
			else
				low += d;
		}
		dp[i] = dd(low, right_cost(low) + dp[i-1].second*low*low);
	}
	printf("%lf\n", dp[n].second*w*w);
	vector<double> ans(n, 0);
	double fac = w;
	for (int i = n; i > 0; i--) {
		fac *= dp[i].first;
		ans[i-1] = fac;
	}
	for (int i = 0; i < min(n, 10); i++)
		printf("%lf\n", ans[i]);
}
