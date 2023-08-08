#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll MOD = (1ll<<31)-1;

int n;
vector<string> grid;
vector<vi> dp, vis;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	grid.assign(n, "");
	rep(i, 0, n) cin >> grid[i];
	dp.assign(n, vi(n, 0));
	vis.assign(n, vi(n, 0));
	dp[0][0] = vis[0][0] = 1;
	rep(i, 0, n) rep(j, 0, n) {
		if (i != n-1 && grid[i+1][j] != '#')
			dp[i+1][j] = (dp[i+1][j]+dp[i][j]) % MOD,
			vis[i+1][j] |= vis[i][j];
		if (j != n-1 && grid[i][j+1] != '#')
			dp[i][j+1] = (dp[i][j+1]+dp[i][j]) % MOD,
			vis[i][j+1] |= vis[i][j];
	}
	if (vis[n-1][n-1]) printf("%lld\n", dp[n-1][n-1]);
	else {
		vis.assign(n, vi(n, 0));
		queue<pii> q;
		q.push({0, 0});
		vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
		while (!q.empty()) {
			auto [x,y] = q.front(); q.pop();
			if (x < 0 || x >= n || y < 0 || y >= n) continue;
			if (vis[x][y] || grid[x][y] == '#') continue;
			vis[x][y] = 1;
			rep(i, 0, 4) q.push({x+dx[i], y+dy[i]});
		}
		if (vis[n-1][n-1]) printf("THE GAME IS A LIE\n");
		else printf("INCONCEIVABLE\n");
	}
}
