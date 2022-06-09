#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6;
ll p[N], c[N];
ll n, M;

bool check(ll d) {
	ll netto = 0;
	for (int i = 0; i < n; i++) {
		netto += max(0ll, p[i]*d - c[i]);
		if (netto >= M)
			return true;
	}
	return false;
}

int main() {
	scanf("%lld%lld", &n, &M);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", p+i, c+i);
	ll low = 0, high = 2e9;
	while (low < high) {
		ll mid = (low + high)/2;
		if (check(mid))
			high = mid;
		else
			low = mid+1;
	}
	printf("%lld\n", low);
}
