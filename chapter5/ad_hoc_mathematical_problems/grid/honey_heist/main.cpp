#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> iii;

int R, N, A, B, X, n;
vector<vi> grid, dist;
vi dx = {0, 1, 1, 0, -1, -1};
vi dy = {1, 1, 0, -1, -1, 0};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> R >> N >> A >> B >> X;
	n = 2*R-1;
	grid.assign(n, vi(n, 0));
	int cnt = 1;
	rep(i, 0, R) rep(j, 0, R+i) grid[i][j] = cnt++;
	rep(i, 0, R-1) rep(j, i+1, n) grid[R+i][j] = cnt++;
	/*rep(i, 0, n) {
		rep(j, 0, n) printf("%3d", grid[i][j]);
		printf("\n");
	}*/
	set<int> walls;
	rep(i, 0, X) {
		int x; cin >> x;
		walls.insert(x);
	}
	pii start, goal;
	rep(i, 0, n) rep(j, 0, n) {
		if (walls.count(grid[i][j]))
			grid[i][j] = 0;
		if (grid[i][j] == A)
			start = {i, j};
		if (grid[i][j] == B)
			goal = {i,j};
	}
	queue<iii> q;
	q.push({0, start.first, start.second});
	dist.assign(n, vi(n, -1));
	while (!q.empty()) {
		auto [d,x,y] = q.front(); q.pop();
		if (x < 0 || x >= n || y < 0 || y >= n) continue;
		if (dist[x][y] != -1) continue;
		if (grid[x][y] == 0) continue;
		dist[x][y] = d;
		rep(i, 0, 6) q.push({d+1, x+dx[i], y+dy[i]});
	}
	int res = dist[goal.first][goal.second];
	if (res > N || res == -1) printf("No\n");
	else printf("%d\n", res);
}
