#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<string> grid;
vector<vi> vis;
vi dx = {-1, -1, -1, 0, 1, 1, 1, 0};
vi dy = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (grid[x][y] == '.' || vis[x][y]) return;
	vis[x][y] = 1;
	rep(i, 0, 8) dfs(x + dx[i], y + dy[i]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	grid.assign(n, "");
	rep(i, 0, n) cin >> grid[i];
	vis.assign(n, vi(m, 0));
	int res = 0;
	rep(i, 0, n) rep(j, 0, m) {
		if (vis[i][j] || grid[i][j] == '.') continue;
		res++;
		dfs(i, j);
	}
	printf("%d\n", res);
}
