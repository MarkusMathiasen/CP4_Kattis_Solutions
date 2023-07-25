#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int H, W;
vector<string> grid;
vector<vi> vis;

pii get_size(int x, int y) {// h,w of image
	int w = 0;
	int h = 0;
	while (x+h < H && grid[x+h][y] == '+') h++;
	while (y+w < W && grid[x][y+w] == '+') w++;
	return {h, w};
}

void remove_image(int x, int y, int h, int w) {
	rep(a, x, x+h) rep(b, y, y+w) grid[a][b] = ' ';
}

void check_image(int x, int y) {
	auto [h,w] = get_size(x, y);
	rep(dh, 0, h) vis[x+dh][y] = w-1;
	rep(dx, 1, h-1) rep(dy, 1, w-1) {
		if (vis[x+dx][y+dy]) {
			dy += vis[x+dx][y+dy];
			continue;
		}
		char& c = grid[x+dx][y+dy];
		if (isalpha(c) || c=='?' || c=='!' || c==',' || c=='.' || c==' ')
			continue;
		if (c == '+')
			check_image(x+dx, y+dy);
		else {
			remove_image(x, y, h, w);
			return;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> H >> W;
	string line; getline(cin, line);
	grid.assign(H, "");
	rep(i, 0, H) getline(cin, grid[i]);
	vis.assign(H, vi(W, 0));
	rep(i, 0, H) rep(j, 0, W) {
		j += vis[i][j];
		if (grid[i][j] == '+')
			check_image(i, j);
	}
	for (string s : grid)
		printf("%s\n", s.c_str());
}
