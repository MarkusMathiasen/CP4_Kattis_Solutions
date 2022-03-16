#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n; scanf("%d%d", &m, &n);
	vector<vector<int>> grid(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &grid[i][j]);
	int r, c; scanf("%d%d", &r, &c); r--; c--;
	bool possible = true;
	vector<int> res;
	vector<bool> moved(100000, false);
	while (true) {
		if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == -2) {
			possible = false;
			break;
		}
		if (grid[r][c] == -1)
			break;
		if (moved[grid[r][c]]) {
			possible = false;
			break;
		}
		res.push_back(grid[r][c]);
		moved[grid[r][c]] = true;
		if (r < m-1 && grid[r+1][c] == grid[r][c])
			r += 2;
		else if (r > 0 && grid[r-1][c] == grid[r][c])
			r -= 2;
		else if (c < n-1 && grid[r][c+1] == grid[r][c])
			c += 2;
		else if (c > 0 && grid[r][c-1] == grid[r][c])
			c -= 2;
		else throw "error";
	}
	if (!possible) {
		printf("impossible\n");
		return 0;
	}
	for (int i = (int)res.size()-1; i >= 0; i--)
		printf("%d ", res[i]);
	printf("\n");
}
