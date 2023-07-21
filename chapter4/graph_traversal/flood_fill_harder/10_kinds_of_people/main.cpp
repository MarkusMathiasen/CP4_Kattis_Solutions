#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int r, c, n, cnt = 1;
vector<vi> grid, comp;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

void dfs(int x, int y, int b) {
	if (x < 0 || x >= r || y < 0 || y >= c) return;
	if (comp[x][y] || grid[x][y] != b) return;
	comp[x][y] = cnt;
	rep(i, 0, 4) dfs(x+dx[i], y+dy[i], b);
}

int main() {
	scanf("%d%d", &r, &c);
	grid.assign(r, vi(c, 0));
	rep(i, 0, r) rep(j, 0, c) {
		char k; scanf(" %c", &k);
		grid[i][j] = k == '1';
	}
	comp.assign(r, vi(c, 0));
	rep(i, 0, r) rep(j, 0, c)
		if (!comp[i][j])
			dfs(i, j, grid[i][j]), cnt++;
	scanf("%d", &n);
	while (n--) {
		int r1, c1, r2, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		r1--, c1--, r2--, c2--;
		if (comp[r1][c1] != comp[r2][c2]) printf("neither\n");
		else printf(grid[r1][c1] == 1 ? "decimal\n" : "binary\n");
	}
}
