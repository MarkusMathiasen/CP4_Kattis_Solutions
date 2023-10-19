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
	string s; cin >> s;
	ll n = sz(s);
	vector<vi> dp(n, vi(n, 1e9));
	rep(i, 0, n) dp[i][i] = 1;
	rep(j, 1, n) for (ll i = j-1; i >= 0; i--) rep(k, 1, j-i+1) {
		ll idx = i+k;
		string sub = s.substr(i, k);
		while (idx+k-1 <= j && s.substr(idx, k) == sub)
			idx += k;
		dp[i][j] = min(dp[i][j], (idx > j ? 0 : dp[idx][j])+dp[i][i+k-1]);
	}
	printf("%lld\n", dp[0][n-1]);
}
