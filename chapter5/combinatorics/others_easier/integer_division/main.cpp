#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, d;
map<ll, ll> m;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> d;
	rep(i, 0, n) {
		ll x; cin >> x;
		m[x/d]++;
	}
	ll res = 0;
	for (auto [i,v] : m)
		res += v*(v-1)/2;
	printf("%lld\n", res);
}
