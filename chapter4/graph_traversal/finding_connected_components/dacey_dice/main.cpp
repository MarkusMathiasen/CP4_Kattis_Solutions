#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, N;
int sx, sy, hx, hy;
vector<vector<char>> grid;
vector<vector<vector<vector<bool>>>> vis;

int south(int up, int right) { // return what points to the south
	if (up == 1) {
		if (right == 2) return 4;
		else if (right == 4) return 5;
		else if (right == 5) return 3;
		else if (right == 3) return 2;
		else assert(false);
	} else if (up == 2) {
		if (right == 1) return 3;
		else if (right == 3) return 6;
		else if (right == 6) return 4;
		else if (right == 4) return 1;
		else assert(false);
	} else if (up == 3) {
		if (right == 1) return 5;
		else if (right == 5) return 6;
		else if (right == 6) return 2;
		else if (right == 2) return 1;
		else assert(false);
	} else if (up == 4) {
		if (right == 1) return 2;
		else if (right == 2) return 6;
		else if (right == 6) return 5;
		else if (right == 5) return 1;
		else assert(false);
	} else if (up == 5) {
		if (right == 1) return 4;
		else if (right == 4) return 6;
		else if (right == 6) return 3;
		else if (right == 3) return 1;
		else assert(false);
	} else if (up == 6) {
		if (right == 2) return 3;
		else if (right == 3) return 5;
		else if (right == 5) return 4;
		else if (right == 4) return 2;
		else assert(false);
	}
	assert(false);
}
int north(int up, int right) {
	return 7-south(up, right);
}
int west(int up, int right) {
	return 7-right;
}
int down(int up, int right) {
	return 7-up;
}

void dfs(int x, int y, int up, int east) {
	if (x < 0 || x >= N || y < 0 || y >= N || grid[x][y] == '*') return;
	if (vis[x][y][up-1][east-1]) return;
	vis[x][y][up-1][east-1] = true;
	dfs(x-1, y, south(up, east), east); // up
	dfs(x+1, y, north(up, east), east); // down
	dfs(x, y+1, west(up, east), up);	// east
	dfs(x, y-1, east, down(up, east));	// west
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		grid.assign(N, vector<char>(N, '.'));
		rep(i, 0, N) rep(j, 0, N) {
			char x; scanf(" %c", &x);
			if (x == 'S') sx = i, sy = j;
			else if (x == 'H') hx = i, hy = j;
			else grid[i][j] = x;
		}
		vis.assign(N, vector<vector<vector<bool>>>(N, vector<vector<bool>>(6, vector<bool>(6, false))));
		dfs(sx, sy, 1, 2);
		bool res = false;
		rep(i, 0, 6) res |= vis[hx][hy][2-1][i];
		printf(res ? "Yes\n" : "No\n");
	}
}
