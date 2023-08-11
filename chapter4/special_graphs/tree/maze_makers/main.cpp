#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, cnt, more_paths;;
vector<vi> grid, p;
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};

void dfs(int x, int y) {
	cnt++;
	rep(i, 0, 4) {
		if (grid[x][y]&(1<<i)) continue;
		if (p[x][y] == i) continue;
		int nx = x+dx[i], ny = y+dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (p[nx][ny] != -1) {
			more_paths = true;
			continue;
		}
		p[nx][ny] = (i+2)%4;
		dfs(nx, ny);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n >> m), n || m) {
		more_paths = cnt = 0;
		grid.assign(n, vi(m, -1));
		rep(i, 0, n) rep(j, 0, m) {
			char c; cin >> c;
			if (isdigit(c)) grid[i][j] = c-'0';
			else grid[i][j] = c-'A'+10;
		}
		vector<pii> entries;
		rep(i, 0, n) {
			if (!(grid[i][0]&1)) entries.push_back({i, 0});
			if (!(grid[i][m-1]&4)) entries.push_back({i, m-1});
		}
		rep(i, 0, m) {
			if (!(grid[0][i]&8)) entries.push_back({0, i});
			if (!(grid[n-1][i]&2)) entries.push_back({n-1, i});
		}
		assert(sz(entries) == 2);
		p.assign(n, vi(m, -1));
		auto [x1,y1] = entries[0];
		p[x1][y1] = -2;
		dfs(x1, y1);
		auto [x2,y2] = entries.back();
		if (p[x2][y2] == -1) printf("NO SOLUTION\n");
		else if (cnt < n*m) printf("UNREACHABLE CELL\n");
		else if (more_paths) printf("MULTIPLE PATHS\n");
		else printf("MAZE OK\n");
	}
}
