#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

void res(ll x) {
	printf("%lld\n", x);
	exit(0);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll p, q; cin >> p >> q;
	if (p%2 == 0) res(0);
	if (q%2 == 1) res(1);
	if (q/2 <= p/2) res(0);
	res(2);
}
