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

ll n;
vi exps;

void find_exps(ll n) {
	for (ll i = 0; p[i]*p[i] <= n; i++) {
		if (n%p[i] == 0) {
			ll cnt = 0;
			while (n%p[i] == 0)
				cnt++,
				n /= p[i];
			exps.push_back(cnt);
		}
	}
	if (n > 1) exps.push_back(1);
}

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n) {
		bool was_neg = n < 0;
		if (was_neg) n = -n;
		exps.clear();
		find_exps(n);
		ll ans = exps[0];
		rep(i, 1, sz(exps)) ans = gcd(ans, exps[i]);
		if (was_neg) {
			while (ans%2 == 0) ans /= 2;
		}
		printf("%lld\n", ans);
	}
}
