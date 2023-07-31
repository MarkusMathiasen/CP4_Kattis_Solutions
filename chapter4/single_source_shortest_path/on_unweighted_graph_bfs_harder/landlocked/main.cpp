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
vector<vi> dist;
map<char, int> locked;
vi dx = {-1, -1, -1, 0, 1, 1, 1, 0};
vi dy = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	grid.assign(n, "");
	rep(i, 0, n) cin >> grid[i];
	dist.assign(n, vi(m, -2));
	deque<pii> q;
	rep(i, 0, n) rep(j, 0, m) {
		if (grid[i][j] == 'W') {
			q.push_back({i, j});
			dist[i][j] = -1;
		}
	}
	while (!q.empty()) { 
		auto [x,y] = q.front(); q.pop_front();
		rep(i, 0, 8) {
			int nx = x+dx[i], ny = y+dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			int cost = grid[x][y]!=grid[nx][ny];
			if (dist[nx][ny] != -2 && dist[nx][ny] <= dist[x][y]+cost)
				continue;
			dist[nx][ny] = dist[x][y]+cost;
			if (cost) q.push_back({nx,ny});
			else q.push_front({nx,ny});
		}
	}
	rep(i, 0, n) rep(j, 0, m) {
		char c = grid[i][j];
		int d = dist[i][j];
		if (!locked.count(c))
			locked[c] = d;
		locked[c] = min(locked[c], d);
	}
	for (auto [c,d] : locked) {
		if (c == 'W') continue;
		printf("%c %d\n", c, d);
	}
}
