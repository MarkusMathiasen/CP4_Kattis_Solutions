#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, M, res = 0;
vector<vi> grid, vis;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

void dfs(int x, int y) {
	if (grid[x][y] == 1 || vis[x][y]) return;
	vis[x][y] = 1;
	rep(i, 0, 4) {
		int nx = x+dx[i], ny = y+dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		res += grid[nx][ny];
		dfs(nx, ny);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	grid.assign(N, vi(M, 0));
	vis.assign(N, vi(M, 0));
	rep(i, 0, N) rep(j, 0, M) {
		char c; scanf(" %c", &c);
		grid[i][j] = c == '1';
	}
	rep(i, 0, N) {
		res += grid[i][0] + grid[i][M-1];
		dfs(i, 0);
		dfs(i, M-1);
	}
	rep(j, 0, M) {
		res += grid[0][j] + grid[N-1][j];
		dfs(0, j);
		dfs(N-1, j);
	}
	printf("%d\n", res);
}
