#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

bool explains(ll len, string& s) {
	string k = s.substr(0, len);
	while (sz(k) < sz(s)) k += k;
	return k.substr(0, sz(s)) == s;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n; cin >> n;
	string line; getline(cin, line);
	while (n--) {
		getline(cin, line);
		ll res = -1;
		rep(i, 1, sz(line)+1) {
			if (explains(i, line)) {
				res = i;
				break;
			}
		}
		printf("%lld\n", res);
	}
}
