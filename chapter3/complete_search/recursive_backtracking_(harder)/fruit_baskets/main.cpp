#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<ll> W;

ll rec(int idx, ll w) {
	if (w >= 200)
		return 0;
	if (idx == N)
		return w;
	return rec(idx+1, w) + rec(idx+1, w+W[idx]);
}

int main() {
	scanf("%d", &N);
	W.assign(N, 0);
	for (int i = 0; i < N; i++)
		scanf("%lld", &W[i]);
	ll total = 0;
	ll mult = (1ll<<(N-1));
	for (ll x : W)
		total += mult*x;
	printf("%lld\n", total - rec(0, 0));
}
