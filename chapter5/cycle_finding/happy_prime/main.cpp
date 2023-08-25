#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T;

bool is_prime(ll n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n%2 == 0) return false;
	for (ll i = 3; i*i <= n; i += 2)
		if (n%i == 0) return false;
	return true;
}

ll next(ll n) {
	ll res = 0;
	while (n) {
		res += (n%10)*(n%10);
		n /= 10;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		ll t, m; cin >> t >> m;
		printf("%lld %lld ", t, m);
		if (!is_prime(m)) {
			printf("NO\n");
			continue;
		}
		unordered_set<ll> seen;
		while (m != 1 && !seen.count(m)) {
			seen.insert(m);
			m = next(m);
		}
		if (m == 1) printf("YES\n");
		else printf("NO\n");
	}
}
