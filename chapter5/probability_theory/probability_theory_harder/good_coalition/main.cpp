#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll S = 150;

ll T, n;
vi s, p;
vector<vector<long double>> dp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		s.assign(n, 0);
		p.assign(n, 0);
		rep(i, 0, n) cin >> s[i] >> p[i];
		dp.assign(n+1, vector<long double>(S+1, 0));
		dp[0][0] = 1;
		rep(i, 0, n) rep(j, 0, S+1) {
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if (j + s[i] <= S)
				dp[i+1][j+s[i]] = max(dp[i+1][j+s[i]], dp[i][j]*p[i]/100);
		}
		long double res = 0;
		rep(j, 76, S+1) res = max(res, dp[n][j]);
		printf("%Lf\n", res*100);
	}
}
