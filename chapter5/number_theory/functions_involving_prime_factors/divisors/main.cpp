#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll N = 432;

bitset<N> b;
vi p;

ll n, k;
map<ll, ll> m;

void sieve() {
	b.set();
	b[0] = b[1] = 0;
	rep(i, 2, N) if (b[i]) {
		for (ll j = i*i; j < N; j += i) b[j] = 0;
		p.push_back(i);
	}
}

void adjust_primes(ll n, ll v) {
	for (ll i = 0; p[i]*p[i] <= n; i++) {
		while (n%p[i] == 0) {
			m[p[i]] += v;
			n /= p[i];
		}
	}
	if (n > 1) m[n] += v;
}

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n >> k) {
		m.clear();
		rep(i, n-k+1, n+1) adjust_primes(i, 1);
		rep(i, 1, k+1) adjust_primes(i, -1);
		ll res = 1;
		for (auto [p,e] : m) res *= e+1;
		printf("%lld\n", res);
	}
}
