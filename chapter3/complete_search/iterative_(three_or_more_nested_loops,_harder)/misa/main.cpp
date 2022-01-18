#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<char>> grid;

int countNeighbors(int x, int y) {
	int res = 0;
	for (int i = max(0, x-1); i <= min(R-1, x+1); i++)
		for (int j = max(0, y-1); j <= min(C-1, y+1); j++)
			res += !(i == x && y == j) && grid[i][j] == 'o';
	return res;
}

int main() {
	scanf("%d%d", &R, &C);
	grid.assign(R, vector<char>(C, 0));
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			scanf(" %c", &grid[i][j]);
	int maxx = -1, maxy = -1, maxn = -1;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			if (grid[i][j] == 'o')
				continue;
			int cn = countNeighbors(i, j);
			if (cn > maxn)
				maxn = cn,
				maxx = i,
				maxy = j;
		}
	if (maxx != -1)
		grid[maxx][maxy] = 'o';
	int res = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (grid[i][j] == 'o')
				res += countNeighbors(i, j);
	printf("%d\n", res/2);
}
