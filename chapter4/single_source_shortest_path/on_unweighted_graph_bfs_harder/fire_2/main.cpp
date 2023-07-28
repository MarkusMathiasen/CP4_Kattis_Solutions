#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, n, m;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> m >> n;
		vector<string> grid(n, "");
		rep(i, 0, n) cin >> grid[i];
		vector<vi> fire(n, vi(m, -1));
		queue<pii> q;
		int sx, sy;
		rep(i, 0, n) rep(j, 0, m)
			if (grid[i][j] == '*') {
				fire[i][j] = 0;
				q.push({i, j});
			} else if (grid[i][j] == '@')
				sx = i, sy = j;

		while (!q.empty()) {
			auto [x,y] = q.front(); q.pop();
			rep(i, 0, 4) {
				int nx = x+dx[i], ny = y+dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (grid[nx][ny] == '#' || fire[nx][ny] != -1) continue;
				fire[nx][ny] = fire[x][y]+1;
				q.push({nx, ny});
			}
		}
		int res = 1e9;
		vector<vi> dist(n, vi(m, -1));
		dist[sx][sy] = 0;
		q.push({sx, sy});
		while (!q.empty()) {
			auto [x,y] = q.front(); q.pop();
			rep(i, 0, 4) {
				int nx = x+dx[i], ny = y+dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					res = min(res, dist[x][y]+1);
					continue;
				}
				if (grid[nx][ny] == '#' || dist[nx][ny] != -1) continue;
				if (fire[nx][ny] != -1 && fire[nx][ny] <= dist[x][y]+1) continue;
				dist[nx][ny] = dist[x][y]+1;
				q.push({nx, ny});
			}
		}
		if (res == 1e9) printf("IMPOSSIBLE\n");
		else printf("%d\n", res);
	}
}
