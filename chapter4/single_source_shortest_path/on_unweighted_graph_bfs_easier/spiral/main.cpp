#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool is_prime(int x) {
	if (x == 2) return true;
	if (x%2 == 0) return false;
	for (int i = 3; i*i <= x; i += 2)
		if (x%i == 0) return false;
	return x != 1;
}

void print_dist(vector<vi>& dist, int d) {
	rep(i, 100-d, 100+d+1) {
		rep(j, 100-d, 100+d+1)
			printf("%4d ", dist[i][j]);
		printf("\n");
	}
}

int main() {
	vector<vi> grid(201, vi(201, 0));
	int cnt = 0;
	int x = 100, y = 100;
	int dir = 0;
	vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
	while (y < 201) {
		grid[x][y] = ++cnt;
		int ndir = (dir+1)%4;
		if (grid[x+dx[ndir]][y+dy[ndir]] == 0)
			dir = ndir;
		x += dx[dir], y += dy[dir];
	}
	vector<vi> valid(201, vi(201, 0));
	rep(i, 0, 201) rep(j, 0, 201)
		valid[i][j] = !is_prime(grid[i][j]);
	for (int t = 1; true; t++) {
		int a, b;
		if (scanf("%d%d", &a, &b) != 2) break;
		vector<vi> dist(201, vi(201, -1));
		int ax, ay, bx, by;
		rep(i, 0, 201) rep(j, 0, 201)
			if (grid[i][j] == a) ax = i, ay = j;
			else if (grid[i][j] == b) bx = i, by = j;
		dist[ax][ay] = 0;
		queue<pii> q;
		q.push({ax, ay});
		while (!q.empty()) {
			auto [x,y] = q.front(); q.pop();
			rep(i, 0, 4) {
				int nx = x+dx[i], ny = y+dy[i];
				if (nx < 0 || nx > 200 || ny < 0 || ny > 200) continue;
				if (dist[nx][ny] != -1 || !valid[nx][ny]) continue;
				dist[nx][ny] = dist[x][y]+1;
				q.push({nx, ny});
			}
		}
		printf("Case %d: ", t);
		if (dist[bx][by] == -1) printf("impossible\n");
		else printf("%d\n", dist[bx][by]);
	}
}
