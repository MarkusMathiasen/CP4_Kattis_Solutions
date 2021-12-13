#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<char>> grid;

int main() {
	scanf("%d%d", &R, &C);
	grid.assign(R, vector<char>(C, ' '));
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			scanf(" %c", &grid[r][c]);
	vector<int> res(5, 0);
	for (int r = 0; r < R-1; r++)
		for (int c = 0; c < C-1; c++) {
			bool building = false;
			int cars = 0;
			for (int dr = 0; dr < 2; dr++)
				for (int dc = 0; dc < 2; dc++) {
					building |= grid[r+dr][c+dc] == '#';
					cars += grid[r+dr][c+dc] == 'X';
				}
			if (!building)
				res[cars]++;
		}
	for (int x : res)
		printf("%d\n", x);
}
