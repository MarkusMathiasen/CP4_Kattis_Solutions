#include <bits/stdc++.h>
using namespace std;

struct que {
	int x;
	int y;
	int d;
	que(int x, int y, int d) : x(x), y(y), d(d) {}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	vector<string> grid(N, "");
	for (int i = 0; i < N; i++)
		cin >> grid[i];
	queue<que> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (grid[i][j] == 'H')
				q.push(que(i, j, 0));
	vector<vector<int>> dist(N, vector<int>(N, -1));
	while (!q.empty()) {
		que v = q.front(); q.pop();
		if (v.x < 0 || v.x >= N || v.y < 0 || v.y >= N)
			continue;
		if (dist[v.x][v.y] != -1)
			continue;
		dist[v.x][v.y] = v.d;
		q.push(que(v.x+1, v.y, v.d+1));
		q.push(que(v.x-1, v.y, v.d+1));
		q.push(que(v.x, v.y+1, v.d+1));
		q.push(que(v.x, v.y-1, v.d+1));
	}
	int res = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (grid[i][j] == 'S')
				res = max(res, dist[i][j]);
	printf("%d\n", res);
}
