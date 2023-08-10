#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<vi> mat, dp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n) {
		mat.assign(n, vi(n, 0));
		rep(i, 0, n) rep(j, 0, n) cin >> mat[i][j];
		cin >> m;
		dp.assign(m+1, vi(n, -1));
		dp[0][0] = 0;
		rep(i, 0, m) rep(j, 0, n) {
			if (dp[i][j] == -1) continue;
			rep(k, 0, n)
				dp[i+1][k] = max(dp[i+1][k], dp[i][j]+mat[j][k]);
		}
		int maximum = 0;
		rep(i, 0, n) maximum = max(maximum, dp[m][i]);
		dp.assign(m+1, vi(n, 1e9));
		dp[0][0] = 0;
		rep(i, 0, m) rep(j, 0, n) {
			if (dp[i][j] == 1e9) continue;
			rep(k, 0, n)
				dp[i+1][k] = min(dp[i+1][k], dp[i][j]+mat[j][k]);
		}
		int minimum = 1e9;
		rep(i, 0, n) minimum = min(minimum, dp[m][i]);
		printf("%d %d\n", maximum, minimum);
	}
}
