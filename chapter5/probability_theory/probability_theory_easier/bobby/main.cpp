#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, r, s, x, y, w;
vector<vi> dp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> r >> s >> x >> y >> w;
		dp.assign(y+1, vi(y+1, 0));
		dp[0][0] = 1;
		rep(rolls, 0, y) rep(success, 0, y) {
			dp[rolls+1][success] += (r-1)*dp[rolls][success];
			dp[rolls+1][success+1] += (s-r+1)*dp[rolls][success];
		}
		ll res = 0;
		rep(success, x, y+1) res += dp[y][success];
		ll p = 1;
		rep(i, 0, y) p *= s;
		if (res*w > p) printf("yes\n");
		else printf("no\n");
	}
}
