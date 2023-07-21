#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> grid(6, "");
vi vis(7, 0);
int sx, sy;

int south(int up, int east) {
	if (up == 1) {
		if (east == 2) return 4;
		if (east == 4) return 5;
		if (east == 5) return 3;
		if (east == 3) return 2;
		assert(false);
	} if (up == 2) {
		if (east == 1) return 3;
		if (east == 3) return 6;
		if (east == 6) return 4;
		if (east == 4) return 1;
		assert(false);
	} if (up == 3) {
		if (east == 1) return 5;
		if (east == 5) return 6;
		if (east == 6) return 2;
		if (east == 2) return 1;
		assert(false);
	}
	return 7 - south(7-up, east);
}
int west(int up, int east) {return 7-east;}
int down(int up, int east) {return 7-up;}
int north(int up, int east) {return 7-south(up, east);}

void dfs(int x, int y, int up, int east) {
	if (x < 0 || x >= 6 || y < 0 || y >= 6 || vis[up] || grid[x][y] != '#') return;
	vis[up] = true;
	dfs(x-1, y, south(up, east), east); // north
	dfs(x+1, y, north(up, east), east); // south
	dfs(x, y-1, east, down(up, east));	// west
	dfs(x, y+1, west(up, east), up);	// east
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	rep(i, 0, 6) cin >> grid[i];
	rep(i, 0, 6) rep(j, 0, 6)
		if (grid[i][j] == '#')
			sx = i, sy = j;
	dfs(sx, sy, 1, 2);
	bool res = true;
	rep(i, 1, 7) res &= vis[i];
	if (res) printf("can fold\n");
	else printf("cannot fold\n");
}
