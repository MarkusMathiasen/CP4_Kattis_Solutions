#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int r, c, n;
vector<vi> grid;
vi dx = {-1, -1, 0, 1, 1, 1, 0, -1};
vi dy = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
	scanf("%d%d", &r, &c);
	grid.assign(r, vi(c, 0));
	rep(i, 0, r) rep(j, 0, c) {
		char c; scanf(" %c", &c);
		grid[i][j] = c - '0';
	}
	scanf("%d", &n);
	while (n--) {
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1--, y1--, x2--, y2--;
		deque<pii> q;
		vector<vi> dist(r, vi(c, -1));
		dist[x1][y1] = 0;
		q.push_back({x1, y1});
		while (!q.empty()) {
			auto [x,y] = q.front(); q.pop_front();
			rep(i, 0, 8) {
				int nx = x+dx[i], ny = y+dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				bool cost = i != grid[x][y];
				if (dist[nx][ny] != -1 &&
					dist[nx][ny] <= dist[x][y]+cost)
					continue; // can't improve
				dist[nx][ny] = dist[x][y]+cost;
				if (cost) q.push_back({nx, ny});
				else q.push_front({nx, ny});
			}
		}
		printf("%d\n", dist[x2][y2]);
	}
}
