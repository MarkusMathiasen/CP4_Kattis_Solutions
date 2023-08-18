#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll N = 1e5+1;

bitset<N> b;
vi p;
ll n;

void sieve() {
	b.set();
	b[0] = b[1] = 0;
	rep(i, 2, N) if (b[i]) {
		for (ll j = i*i; j < N; j += i) b[j] = 0;
		p.push_back(i);
	}
}

ll prime_sum(ll n) {
	ll res = 0;
	for (ll i = 0; p[i]*p[i] <= n; i++) {
		while (n%p[i] == 0)
			n /= p[i],
			res += p[i];
	}
	if (n > 1) res += n;
	return res;
}

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n != 4) {
		ll res = 1;
		ll ps = prime_sum(n);
		while (ps != n) {
			res++;
			n = ps;
			ps = prime_sum(n);
		}
		printf("%lld %lld\n", n, res);
	}
}
