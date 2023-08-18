#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll N = 14e3+1;

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
vi S, rev, dp;

ll count_primes(ll x) {
	ll res = 0;
	for (ll i = 0; p[i]*p[i] <= x; i++) {
		res += x%p[i] == 0;
		while (x%p[i] == 0) x /= p[i];
	}
	return res + (x > 1);
}

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	S.assign(n, 0);
	rep(i, 0, n) cin >> S[i];
	rev.assign(1<<n, 0);
	// compute revenue for all subsets
	rep(subset, 0, 1<<n) {
		ll sum = 0;
		int a = (int)subset;
		while (a) {
			ll i = __builtin_ctz(a);
			a ^= 1<<i;
			sum += S[i];
		}
		rev[subset] = count_primes(sum);
	}
	// fill dp
	dp.assign(1<<n, 0);
	rep(state, 1, 1<<n) {
		int ones = __builtin_popcount((int)state);
		rep(sub, 1, 1<<ones) {
			int a = (int)state;
			int n_state = 0;
			rep(i, 0, ones) {
				if ((1<<i)&sub)
					n_state += a&(-a);
				a ^= a&(-a);
			}
			dp[state] = max(dp[state], dp[state^n_state]+rev[n_state]);
		}
	}
	printf("%lld\n", dp[(1<<n)-1]);
}
