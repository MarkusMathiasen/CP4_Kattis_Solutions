#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, s, k;
vector<vector<long double>> dp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> s >> k;
	dp.assign(n+1, vector<long double>(s+1, 0));
	dp[0][0] = 1;
	rep(i, 0, n) rep(j, 0, s+1) {
		dp[i+1][j] += dp[i][j]*(long double)j/(long double)s;
		if (j != s)
			dp[i+1][j+1] += dp[i][j]*(long double)(s-j)/(long double)s;
	}
	long double res = 0;
	rep(i, k, s+1) res += dp[n][i];
	printf("%.8Lf\n", res);
}
