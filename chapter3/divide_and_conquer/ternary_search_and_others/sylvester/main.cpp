#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		ll n, x, y, w, h; scanf("%lld%lld%lld%lld%lld", &n, &x, &y, &w, &h);
		for (ll j = y; j < y+h; j++) {
			for (ll i = x; i < x+w; i++) {
				int v = 1;
				ll a = i, b = j, s = n;
				while (s > 1) {
					s /= 2;
					if (a >= s && b >= s)
						v = -v;
					if (a >= s)
						a -= s;
					if (b >= s)
						b -= s;
				}
				printf("%d ", v);
			}
			printf("\n");
		}
		printf("\n");
	}
}
