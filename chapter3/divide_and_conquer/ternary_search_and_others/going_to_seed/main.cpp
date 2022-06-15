#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n; scanf("%lld", &n);
	ll low = 1, high = n;
	while (low < high) {
		high = min(high+1, n);
		low = max(1ll, low-1);
		ll d = high - low + 1;
		ll l1 = low + d/4;
		ll l2 = low + d/2;
		ll r1 = low + d*3/4-1;
		ll r2 = high;
		printf("Q %lld %lld %lld %lld\n", l1, r1, l2, r2);
		fflush(stdout);
		ll w1, w2; scanf("%lld%lld", &w1, &w2);
		if (w1 && !w2)
			low = l1, high = l2-1;
		if (!w1 && w2)
			low = r1+1, high = r2;
		if (w1 && w2)
			low = l2, high = r1;
		if (!w1 && !w2)
			high = l1-1;
	}
	printf("A %lld\n", low);
	fflush(stdout);
}
