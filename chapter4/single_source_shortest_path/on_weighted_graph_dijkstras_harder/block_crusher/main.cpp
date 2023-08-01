#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int, int, int> iiii;

int n, m;
vector<vi> grid, dist;
vector<vector<pii>> pre;
vi dx = {-1, -1, -1, 0, 1, 1, 1, 0};
vi dy = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	while (scanf("%d%d", &n, &m), n || m) {
		grid.assign(n, vi(m, -1));
		rep(i, 0, n) rep(j, 0, m) {
			char c; scanf(" %c", &c);
			grid[i][j] = c-'0';
		}
		dist.assign(n, vi(m, -1));
		pre.assign(n, vector<pii>(m, {-1, -1}));
		priority_queue<iiii, vector<iiii>, greater<iiii>> pq;
		rep(i, 0, m) pq.push({grid[0][i], 0, i, -2, -2});
		while (!pq.empty()) {
			auto [d,x,y,px,py] = pq.top(); pq.pop();
			if (dist[x][y] != -1) continue;
			dist[x][y] = d;
			pre[x][y] = {px,py};
			rep(i, 0, 8) {
				int nx = x+dx[i], ny = y+dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				pq.push({d+grid[nx][ny], nx, ny, x, y});
			}
		}
		int x = n-1, y = 0;
		rep(i, 0, m) if (dist[x][i] < dist[x][y]) y = i;
		while (x != -2 && y != -2) {
			grid[x][y] = 0;
			auto [a,b] = pre[x][y];
			x = a, y = b;
		}
		rep(i, 0, n) {
			rep(j, 0, m)
				if (grid[i][j] == 0) printf(" ");
				else printf("%d", grid[i][j]);
			printf("\n");
		}
		printf("\n");
	}
}
