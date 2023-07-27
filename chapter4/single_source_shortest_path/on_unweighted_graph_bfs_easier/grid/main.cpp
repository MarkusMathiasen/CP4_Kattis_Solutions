#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<vi> grid(n, vi(m, 0));
	rep(i, 0, n) rep(j, 0, m) {
		char c; scanf(" %c", &c);
		grid[i][j] = c - '0';
	}
	queue<pii> q;
	vector<vi> dist(n, vi(m, -1));
	q.push({0, 0});
	dist[0][0] = 0;
	vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
	while (!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		rep(i, 0, 4) {
			int nx = dx[i]*grid[x][y]+x;
			int ny = dy[i]*grid[x][y]+y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[x][y]+1;
			q.push({nx, ny});
		}
	}
	printf("%d\n", dist[n-1][m-1]);
}
