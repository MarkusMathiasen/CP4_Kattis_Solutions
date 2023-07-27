#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int X, Y, T, L, W;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
vector<vi> grid;

int sgn(int a) {
	if (a < 0) return -1;
	return a > 0;
}

void print_grid() {
	for (int j = Y-1; j >= 0; j--) {
		rep(i, 0, X)
			printf("%3d ", grid[i][j]);
		printf("\n");
	}
}

int main() {
	while (scanf("%d%d%d%d%d", &X, &Y, &T, &L, &W) == 5) {
		grid.assign(X, vi(Y, 0));
		queue<pii> q;
		while (L--) {
			int x, y; scanf("%d%d", &x, &y); x--, y--;
			grid[x][y] = T;
			q.push({x, y});
		}
		while (W--) {
			int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x1--, y1--, x2--, y2--;
			int x = x1, y = y1;
			grid[x][y] = -1;
			while (x != x2 || y != y2) {
				x += sgn(x2-x1);
				y += sgn(y2-y1);
				grid[x][y] = -1;
			}
		}
		int res = 0;
		while (!q.empty()) {
			res++;
			auto [x,y] = q.front(); q.pop();
			if (grid[x][y] == 1) continue;
			rep(i, 0, 4) {
				int nx = x+dx[i], ny = y+dy[i];
				if (nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
				if (grid[nx][ny]) continue;
				grid[nx][ny] = grid[x][y]-1;
				q.push({nx, ny});
			}
		}
		printf("%d\n", res);
	}
}
