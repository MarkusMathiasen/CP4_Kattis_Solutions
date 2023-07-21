#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int W, H;
vector<string> grid;
int px, py;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

int dfs(int x, int y) {
	if (grid[x][y] == '#' || grid[x][y] == 'T') return 0;
	int res = grid[x][y] == 'G';
	grid[x][y] = '#';
	rep(i, 0, 4)
		if (grid[x+dx[i]][y+dy[i]] == 'T')
			return res;
	rep(i, 0, 4) res += dfs(x + dx[i], y + dy[i]);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> W >> H;
	grid.assign(H, "");
	rep(i, 0, H) cin >> grid[i];
	rep(i, 0, H) rep(j, 0, W)
		if (grid[i][j] == 'P') px = i, py = j;
	printf("%d\n", dfs(px, py));
}
