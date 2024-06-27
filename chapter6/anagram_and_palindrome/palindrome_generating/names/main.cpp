#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

string s;
ll res;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	res = sz(s);
	rep(adds, 0, sz(s)) {
		ll attempt = adds;
		rep(i, adds, (sz(s)+adds)/2) {
			attempt += s[i] != s[sz(s)+adds-1-i];
		}
		res = min(res, attempt);
	}
	assert(res < sz(s));
	printf("%lld\n", res);
}
