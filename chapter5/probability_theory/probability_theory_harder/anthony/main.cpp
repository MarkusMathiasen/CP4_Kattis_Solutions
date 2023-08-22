#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, m;
vector<vector<long double>> dp;
vector<long double> p;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	dp.assign(n+m, vector<long double>(n+1, 0));
	dp[0][0] = 1;
	p.assign(n+m+1, 0);
	rep(i, 0, n+m-1) cin >> p[i];
	rep(i, 0, n+m-1) rep(j, 0, n) {
		if (i-j >= m)
			continue;
		dp[i+1][j] += dp[i][j]*p[i];
		dp[i+1][j+1] += dp[i][j]*(1-p[i]);
	}
	long double res = 0;
	rep(i, 0, n) res += dp[m+i][i];
	printf("%Lf\n", res);
}
