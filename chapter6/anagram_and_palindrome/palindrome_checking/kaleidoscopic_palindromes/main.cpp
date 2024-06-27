#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll a, b, k;

bool is_pal_in_base(ll x, ll b) {
	vi v;
	while (x) {
		v.push_back(x%b);
		x/=b;
	}
	rep(i, 0, sz(v)/2) if (v[i] != v[sz(v)-1-i]) return false;
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b >> k;
	ll res = 0;
	rep(i, a, b+1) {
		bool is_pal = true;
		rep(j, 2, k+1) if (!is_pal_in_base(i, j)) {
			is_pal = false;
			break;
		}
		res += is_pal;
	}
	printf("%lld\n", res);
}
