#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x[800], y[800];

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lld", x+i);
		for (int i = 0; i < n; i++)
			scanf("%lld", y+i);
		sort(x, x+n);
		sort(y, y+n);
		ll res = 0;
		for (int i = 0; i < n; i++)
			res += x[i] * y[n-i-1];
		printf("Case #%d: %lld\n", t, res);
	}
}
