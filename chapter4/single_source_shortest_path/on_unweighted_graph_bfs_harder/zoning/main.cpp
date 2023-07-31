#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<vi> grid, dist;

int main() {
	scanf("%d", &n);
	grid.assign(n, vi(n, 0));
	dist.assign(n, vi(n, -1));
	queue<pii> q;
	rep(i, 0, n) rep(j, 0, n) {
		char c; scanf(" %c", &c);
		if (c == '3') {
			q.push({i,j});
			dist[i][j] = 0;
		}
		grid[i][j] = c-'0';
	}
	int res = 0;
	vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
	while (!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		if (grid[x][y] == 1) res = max(res, dist[x][y]);
		rep(i, 0, 4) {
			int nx = x+dx[i], ny = y+dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[x][y]+1;
			q.push({nx,ny});
		}
	}
	printf("%d\n", res);
}
