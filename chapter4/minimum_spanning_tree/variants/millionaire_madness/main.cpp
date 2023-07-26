#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<vi> grid, vis;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

bool dfs(int x, int y, int h) {
	if (vis[x][y]) return false;
	if (x == n-1 && y == m-1) return true;
	vis[x][y] = 1;
	rep(i, 0, 4) {
		int nx = x+dx[i], ny = y+dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (grid[nx][ny] - grid[x][y] > h) continue;
		if (dfs(nx, ny, h)) return true;
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	grid.assign(n, vi(m, 0));
	rep(i, 0, n) rep(j, 0, m) scanf("%d", &grid[i][j]);
	int upper = 1e9, lower = 0;
	while (lower < upper) {
		int mid = (upper+lower)/2;
		vis.assign(n, vi(m, 0));
		if (dfs(0, 0, mid)) upper = mid;
		else lower = mid+1;
	}
	printf("%d\n", lower);
}
