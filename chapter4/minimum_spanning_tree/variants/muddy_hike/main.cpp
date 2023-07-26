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

bool dfs(int x, int y, int mud) {
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	if (grid[x][y] > mud || vis[x][y]) return false;
	if (y == m-1) return true;
	vis[x][y] = 1;
	rep(i, 0, 4) if (dfs(x+dx[i], y+dy[i], mud)) return true;
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	grid.assign(n, vi(m, 0));
	rep(i, 0, n) rep(j, 0, m) scanf("%d", &grid[i][j]);
	int low = 0, high = 1e6;
	while (low < high) {
		int mid = (low+high)/2;
		vis.assign(n, vi(m, 0));
		bool res = false;
		rep(i, 0, n) res |= dfs(i, 0, mid);
		if (res) high = mid;
		else low = mid+1;
	}
	printf("%d\n", low);
}
