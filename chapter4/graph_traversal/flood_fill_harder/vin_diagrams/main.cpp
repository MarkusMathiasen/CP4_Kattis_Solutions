#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
int ax, ay, bx, by, ix, iy;
vector<string> grid;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

void dfs_line(int x, int y) {
	rep(i, 0, 4) {
		int nx = x+dx[i], ny = y+dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (grid[nx][ny] == 'I')
			nx += dx[i], ny += dy[i];
		if (grid[nx][ny] == 'X') {
			grid[nx][ny] = grid[x][y];
			dfs_line(nx, ny);
		}
	}
}

void dfs_elim(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (grid[x][y] != '.') return;
	grid[x][y] = '#';
	rep(i, 0, 4)
		dfs_elim(x+dx[i], y+dy[i]);
}

int dfs_count(int x, int y) {
	if (grid[x][y] != '.') return 0;
	grid[x][y] = 'C';
	int res = 1;
	rep(i, 0, 4) res += dfs_count(x+dx[i], y+dy[i]);
	return res;
}

void print_grid() {
	rep(i, 0, n) printf("%s\n", grid[i].c_str());
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	grid.assign(n, "");
	rep(i, 0, n) cin >> grid[i];
	rep(i, 0, n) rep(j, 0, m) { // Find A and B
		if (grid[i][j] == 'A') ax = i, ay = j;
		if (grid[i][j] == 'B') bx = i, by = j;
	}	
	rep(i, 1, n-1) rep(j, 1, m-1) // Find intersections
		if (grid[i][j] == 'X' && grid[i-1][j] == 'X' && grid[i+1][j] == 'X'
				&& grid[i][j-1] == 'X' && grid[i][j+1] == 'X')
			grid[i][j] = 'I',
			ix = i, iy = j;
	dfs_line(ax, ay);	// Mark lines
	dfs_line(bx, by);
	rep(i, 0, n) {		// remove edge dots
		dfs_elim(i, 0);
		dfs_elim(i, m-1);
	}
	rep(j, 0, m) {
		dfs_elim(0, j);
		dfs_elim(n-1, j);
	}
	//print_grid();
	int hx, hy;
	for (int dxi = -1; dxi <= 1; dxi += 2)
		for (int dyi = -1; dyi <= 1; dyi += 2)
			if (grid[ix+dxi][iy+dyi] == '#')
				hx = dxi, hy = dyi;
	int ares = dfs_count(ix-hx, iy+hy);
	int bres = dfs_count(ix+hx, iy-hy);
	int ires = dfs_count(ix-hx, iy-hy);
	if (grid[ix][iy+hy] == 'B')
		swap(ares, bres);
	printf("%d %d %d\n", ares, bres, ires);
}
