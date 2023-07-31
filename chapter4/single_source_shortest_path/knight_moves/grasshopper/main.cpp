#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, sx, sy, gx, gy;
vi dx = {-2, -2, -1, 1, 2, 2, 1, -1};
vi dy = {-1, 1, 2, 2, 1, -1, -2, -2};

int main() {
	while (scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &gx, &gy) == 6) {
		sx--, sy--, gx--, gy--;
		vector<vi> dist(n, vi(m, -1));
		dist[sx][sy] = 0;
		queue<pii> q; q.push({sx, sy});
		while (!q.empty()) {
			auto [x,y] = q.front(); q.pop();
			rep(i, 0, 8) {
				int nx = x+dx[i], ny = y+dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[x][y]+1;
				if (nx == gx && ny == gy) break;
				q.push({nx, ny});
			}
		}
		if (dist[gx][gy] == -1) printf("impossible\n");
		else printf("%d\n", dist[gx][gy]);
	}
}
