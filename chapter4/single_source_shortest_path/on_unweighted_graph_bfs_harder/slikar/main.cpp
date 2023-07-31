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
vector<vi> water, dist;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
int gx, gy, sx, sy;

void print_grid() {
	for (string& s : grid)
		printf("%s\n", s.c_str());
}
void print_table(vector<vi>& table) {
	rep(i, 0, n) {
		rep(j, 0, m) printf("%3d ", table[i][j]);
		printf("\n");
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	grid.assign(n, "");
	rep(i, 0, n) cin >> grid[i];
	water.assign(n, vi(m, -1));
	dist.assign(n, vi(m, -1));
	queue<pii> q;
	rep(i, 0, n) rep(j, 0, m) {
		if (grid[i][j] == 'D') {
			water[i][j] = -2;
			gx = i, gy = j;
		} else if (grid[i][j] == 'S')
			sx = i, sy = j;
		else if (grid[i][j] == '*') {
			q.push({i,j});
			water[i][j] = 0;
		}
	}
	while (!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		rep(i, 0, 4) {
			int nx = x+dx[i], ny = y+dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (water[nx][ny] != -1 || grid[nx][ny] == 'X')
				continue;
			water[nx][ny] = water[x][y]+1;
			q.push({nx, ny});
		}
	}
	q.push({sx, sy});
	dist[sx][sy] = 0;
	while (!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		rep(i, 0, 4) {
			int nx = x+dx[i], ny = y+dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (dist[nx][ny] != -1 || grid[nx][ny] == 'X')
				continue;
			if (grid[nx][ny] != 'D' && water[nx][ny] != -1
				&& water[nx][ny] <= dist[x][y]+1)
				continue;
			dist[nx][ny] = dist[x][y]+1;
			q.push({nx, ny});
		}
	}
	if (dist[gx][gy] == -1) printf("KAKTUS\n");
	else printf("%d\n", dist[gx][gy]);
}
