#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int res = 0;
		double torque = -1;
		for (int gear = 1; gear <= n; gear++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c); a = -a;
			double yt = -(b*b - 4*a*c)/(4.0*a);
			if (yt > torque)
				torque = yt,
				res = gear;
		}
		printf("%d\n", res);
	}
}
