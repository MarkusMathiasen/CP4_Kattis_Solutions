#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, H, W, cnt=1;
vector<vi> grid, dp;

int fill(int h, int w) {
	if (dp[h][w]) return dp[h][w];
	int sh = -1, sw = -1, v = 1e9;
	if (h > 0 && v > grid[h-1][w])
		sh = h-1, sw = w, v = grid[h-1][w];
	if (w > 0 && v > grid[h][w-1])
		sh = h, sw = w-1, v = grid[h][w-1];
	if (w < W-1 && v > grid[h][w+1])
		sh = h, sw = w+1, v = grid[h][w+1];
	if (h < H-1 && v > grid[h+1][w])
		sh = h+1, sw = w, v = grid[h+1][w];
	return dp[h][w] = v < grid[h][w] ? fill(sh, sw) : cnt++;
}

int main() {
	scanf("%d", &T);
	rep(t, 1, T+1) {
		scanf("%d%d", &H, &W);
		grid.assign(H, vi(W, 0));
		dp.assign(H, vi(W, 0));
		rep(h, 0, H) rep(w, 0, W)
			scanf("%d", &grid[h][w]);
		rep(h, 0, H) rep(w, 0, W)
			fill(h, w);
		char c = 'a';
		map<int, char> m;
		rep(h, 0, H) rep(w, 0, W)
			if (!m.count(dp[h][w]))
				m[dp[h][w]] = c++;
		printf("Case #%d:\n", t);
		rep(h, 0, H) {
			rep(w, 0, W)
				printf("%c ", m[dp[h][w]]);
			printf("\n");
		}
	}
}
