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
int sx, sy;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	grid.assign(n, "");
	rep(i, 0, n) cin >> grid[i];
	cin >> sx >> sy; sx--; sy--;
	deque<pii> q; q.push_back({sx, sy});
	dist.assign(n, vi(m, -1));
	dist[sx][sy] = 1;
	int res = -1;
	while (!q.empty()) {
		auto [x,y] = q.front(); q.pop_front();
		rep(i, 0, 4) {
			int nx = x+dx[i], ny = y+dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				res = dist[x][y];
				goto end;
			}
			if (grid[nx][ny] == '#') continue;
			int cost = grid[nx][ny] == 'c';
			if (dist[nx][ny] != -1 && dist[nx][ny] <= dist[x][y]+cost)
				continue;
			dist[nx][ny] = dist[x][y]+cost;
			if (cost) q.push_back({nx, ny});
			else q.push_front({nx, ny});
		}
	}
end:
	printf("%d\n", res);
}
