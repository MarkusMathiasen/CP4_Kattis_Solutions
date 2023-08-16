#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int r, k, N;
vi K;
vector<vi> grid, vis;
vi dx = {-1, 0, 1, 1, 0, -1};
vi dy = {0, 1, 1, 0, -1, -1};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> r >> k; N = 2*r+1;
	grid.assign(N, vi(N, 0));
	int cnt = 1;
	rep(i, 1, r+1) rep(j, 1, r+i) grid[i][j] = cnt++;
	rep(i, 1, r) rep(j, i+1, 2*r) grid[r+i][j] = cnt++;
	/*rep(i, 0, N) {
		rep(j, 0, N) printf("%4d", grid[i][j]);
		printf("\n");
	}*/
	K.assign(cnt, 0);
	rep(i, 0, k) {
		int x; cin >> x;
		K[x] = 1;
	}
	int res = 0;
	vis.assign(N, vi(N, 0));
	queue<pii> q;
	q.push({0, 0});
	while (!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		if (x < 0 || x >= N || y < 0 || y >= N) continue;
		else if (K[grid[x][y]]) {res++; continue;}
		else if (vis[x][y]) continue;
		vis[x][y] = 1;
		rep(i, 0, 6) q.push({x+dx[i], y+dy[i]});
	}
	printf("%d\n", res);
}
