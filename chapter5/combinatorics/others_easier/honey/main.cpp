#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef tuple<ll, ll, ll> iii;

map<iii, ll> dp;
vi dx = {0, 1, 1, 0, -1, -1}, dy = {1, 1, 0, -1, -1, 0};
ll T, n;

int main() {
	dp[{0, 0, 0}] = 1;
	rep(s, 1, 15) rep(x, -14, 15) rep(y, -14, 15) {
		ll res = 0;
		rep(i, 0, 6)
			res += dp[{x+dx[i], y+dy[i], s-1}];
		dp[{x, y, s}] = res;
	}
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		printf("%lld\n", dp[{0, 0, n}]);
	}
}
