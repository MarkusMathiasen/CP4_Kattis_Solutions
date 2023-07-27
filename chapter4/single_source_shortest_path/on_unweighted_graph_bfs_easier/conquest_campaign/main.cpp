#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int R, C, N; scanf("%d%d%d", &R, &C, &N);
	vector<vi> dist(R, vi(C, 0));
	queue<pii> q;
	rep(i, 0, N) {
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		q.push({x, y});
		dist[x][y] = 1;
	}
	vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
	int res = 0;
	while (!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		res = max(res, dist[x][y]);
		rep(i, 0, 4) {
			int nx = dx[i]+x;
			int ny = dy[i]+y;
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (dist[nx][ny]) continue;
			dist[nx][ny] = dist[x][y]+1;
			q.push({nx, ny});
		}
	}
	printf("%d\n", res);
}
