#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int m, n, t = 0;
vector<string> grid;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

void dfs(int x, int y) {
	if (x < 0 || x >= m || y < 0 || y >= n) return;
	if (grid[x][y] == '#') return;
	grid[x][y] = '#';
	rep(i, 0, 4) dfs(x + dx[i], y + dy[i]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> m >> n) {
		t++;
		grid.assign(m, "");
		rep(i, 0, m) cin >> grid[i];
		int res = 0;
		rep(i, 0, m) rep(j, 0, n) {
			if (grid[i][j] != '#') {
				res++;
				dfs(i, j);
			}
		}
		printf("Case %d: %d\n", t, res);
	}
}
