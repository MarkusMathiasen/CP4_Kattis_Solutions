#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		ll res = 0;
		while (n--) {
			ll x, y; cin >> x >> y;
			ll d2 = x*x+y*y;
			rep(i, 1, 11) if (d2 <= i*i*400) {
				res += 11-i;
				break;
			}
		}
		printf("%lld\n", res);
	}
}
