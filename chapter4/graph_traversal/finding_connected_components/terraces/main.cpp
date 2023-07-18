#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int W, H, cnt = 0;
vector<vi> grid, comp;
vi dh = {-1, 1, 0, 0}, dw = {0, 0, -1, 1};
vi comp_size, sink;

void ass_comp(int h, int w) {
	comp_size[comp[h][w]]++;
	rep(i, 0, 4) {
		int nh = h+dh[i];
		int nw = w+dw[i];
		if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
		if (grid[h][w] == grid[nh][nw] && comp[nh][nw] == -1) {
			comp[nh][nw] = comp[h][w];
			ass_comp(nh, nw);
		}
	}
}

int main() {
	scanf("%d%d", &W, &H);
	grid.assign(H, vi(W, 0));
	rep(i, 0, H) rep(j, 0, W)
		scanf("%d", &grid[i][j]);
	comp.assign(H, vi(W, -1));
	comp_size.assign(W*H, 0);
	sink.assign(W*H, 1);
	rep(i, 0, H) rep(j, 0, W) {
		if (comp[i][j] == -1) {
			comp[i][j] = cnt++;
			ass_comp(i, j);
		}
	}

	rep(i, 0, H) rep(j, 0, W) rep(k, 0, 4) {
		int ni = i+dh[k], nj = j+dw[k];
		if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
		if (grid[i][j] > grid[ni][nj]) sink[comp[i][j]] = false;
	}
	int res = 0;
	rep(c, 0, cnt)
		if (sink[c])
			res += comp_size[c];
	printf("%d\n", res);
}
