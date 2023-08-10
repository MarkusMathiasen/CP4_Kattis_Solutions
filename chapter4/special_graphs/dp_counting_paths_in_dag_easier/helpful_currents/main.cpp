#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, x_init, MOD = 1000003, res, reach;
vector<string> grid;
vector<vi> dp, vis;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> x_init;
	grid.assign(n, "");
	rep(i, 0, n) cin >> grid[i];
	dp.assign(n, vi(m, 0));
	vis.assign(n, vi(m, 0));
	dp[n-1][x_init] = vis[n-1][x_init] = 1;
	for (int row = n-1; row >= 0; row--) {
		// relax left to right
		rep(col, 0, m-1) if (grid[row][col] == '>')
			dp[row][col+1] = (dp[row][col+1]+dp[row][col])%MOD,
			vis[row][col+1] |= vis[row][col];
		// relax right to left
		for (int col = m-1; col > 0; col--) if (grid[row][col] == '<')
			dp[row][col-1] = (dp[row][col-1]+dp[row][col])%MOD,
			vis[row][col-1] |= vis[row][col];
		// relax up, if not in top
		if (row) rep(col, 0, m) if (grid[row][col] != '#')
			dp[row-1][col] = dp[row][col],
			vis[row-1][col] |= vis[row][col];
	}
	rep(i, 0, n) rep(j, 0, m) if (grid[i][j] == '@')
		res = dp[i][j],
		reach = vis[i][j];
	if (reach) printf("%d\n", res);
	else printf("begin repairs\n");
}
