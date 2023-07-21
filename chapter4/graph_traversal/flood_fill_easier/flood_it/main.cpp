#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, n;
vector<vi> grid;
vector<vi> vis;
bool change;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1}, used;

int dfs(int x, int y, int color) {
	if (x < 0 || x >= n || y < 0 || y >= n) return 0;
	if (vis[x][y] || (grid[x][y] && grid[x][y] != color)) return 0;
	vis[x][y] = 1;
	int res = grid[x][y] != 0;
	if (grid[x][y] && change) grid[x][y] = 0;
	rep(i, 0, 4) res += dfs(x+dx[i], y + dy[i], color);
	return res;
}

int flood(int color, bool ch) {
	change = ch;
	vis.assign(n, vi(n, 0));
	return dfs(0, 0, color);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		grid.assign(n, vi(n, 0));
		used.assign(7, 0);
		rep(i, 0, n) rep(j, 0, n) {
			char c; scanf(" %c", &c);
			grid[i][j] = c-'0';
		}
		flood(grid[0][0], true);
		int res = 0;
		while (true) {
			int best_color = 0, changed = 0;
			rep(c, 1, 7) {
				int new_changed = flood(c, false);
				if (new_changed > changed) {
					changed = new_changed;
					best_color = c;
				}
			}
			if (best_color == 0) break;
			flood(best_color, true);
			used[best_color]++;
			res++;
		}
		printf("%d\n", res);
		rep(i, 1, 7) printf("%d ", used[i]);
		printf("\n");
	}
}
