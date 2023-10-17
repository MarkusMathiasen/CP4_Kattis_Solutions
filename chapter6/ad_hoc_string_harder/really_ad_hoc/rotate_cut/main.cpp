#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll T; cin >> T;
	while (T--) {
		ll ops; string s; cin >> ops >> s;
		ll a = 0, b = sz(s);
		rep(i, 0, ops) {
			ll l = b-a;
			ll r = l/4;
			if (!r) break;
			if (i%2) b -= r;
			else a += r;
		}
		string res(s.begin()+a, s.begin()+b);
		printf("%s\n", res.c_str());
	}
}
