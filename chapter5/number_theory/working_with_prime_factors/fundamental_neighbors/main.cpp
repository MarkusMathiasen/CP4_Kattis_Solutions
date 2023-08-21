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

void sieve() {
	b.set();
	b[0] = b[1] = 0;
	rep(i, 2, N) if (b[i]) {
		for (ll j = i*i; j < N; j += i) b[j] = 0;
		p.push_back(i);
	}
}

ll pow(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	ll p = pow(a, b/2);
	return p*p*(b%2 ? a : 1);
}

ll neigh(ll n) {
	ll res = 1;
	for (ll i = 0; p[i]*p[i] <= n; i++) {
		if (n%p[i] == 0) {
			ll cnt = 0;
			while (n%p[i] == 0)
				cnt++,
				n /= p[i];
			res *= pow(cnt, p[i]);
		}
	}
	return res;
}

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	ll n;
	while (cin >> n) {
		printf("%lld %lld\n", n, neigh(n));
	}
}
