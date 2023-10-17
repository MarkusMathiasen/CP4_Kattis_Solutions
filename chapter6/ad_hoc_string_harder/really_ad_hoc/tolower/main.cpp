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
	ll P, T; cin >> P >> T;
	ll res = 0;
	while (P--) {
		bool solved = true;
		rep(i, 0, T) {
			string s; cin >> s;
			rep(j, 1, sz(s))
				solved &= (bool)islower(s[j]);
		}
		res += solved;
	}
	printf("%lld\n", res);
}
