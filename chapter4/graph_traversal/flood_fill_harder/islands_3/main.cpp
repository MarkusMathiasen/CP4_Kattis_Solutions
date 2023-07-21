#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, res = 0;
vector<string> grid;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (grid[x][y] == 'W') return;
	grid[x][y] = 'W';
	rep(i, 0, 4) dfs(x+dx[i], y+dy[i]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	grid.assign(n, "");
	rep(i, 0, n) cin >> grid[i];
	rep(i, 0, n) rep(j, 0, m)
		if (grid[i][j] == 'L')
			dfs(i, j), res++;
	printf("%d\n", res);
}
