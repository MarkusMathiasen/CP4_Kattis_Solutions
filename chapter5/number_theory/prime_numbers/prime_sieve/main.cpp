#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll N = 1e8+1;

ll n, q, cnt = 0;
bitset<N> b;



int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	// Sieve
	b.set();
	b[0] = b[1] = 0;
	rep(i, 2, n+1) if (b[i]) {
		cnt++;
		for (ll j = i*i; j <= n; j += i) b[j] = 0;
	}
	printf("%lld\n", cnt);
	while (q--) {
		ll x; cin >> x;
		printf("%d\n", (int)b[x]);
	}
}
