#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> iii;

int T, H, n, m;
vector<vi> upper, lower;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

bool outside(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}

int passable(int x1, int y1, int x2, int y2, int h) {
	if (lower[x1][y1] + 50 > upper[x2][y2]) return -1;
	if (lower[x2][y2] + 50 > upper[x2][y2]) return -1;
	if (lower[x2][y2] + 50 > upper[x1][y1]) return -1;
	if (h + 50 > upper[x2][y2]) return h+50 - upper[x2][y2];
	return 0;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(t, 1, T+1) {
		cin >> H >> n >> m;
		upper.assign(n, vi(m, 0));
		lower.assign(n, vi(m, 0));
		rep(i, 0, n) rep(j, 0, m) cin >> upper[i][j];
		rep(i, 0, n) rep(j, 0, m) cin >> lower[i][j];
		priority_queue<iii, vector<iii>, greater<iii>> pq;
		vector<vi> vis(n, vi(m, 0));
		queue<pii> q;
		q.push({0, 0});
		while (!q.empty()) {
			auto [x,y] = q.front(); q.pop();
			if (vis[x][y]) continue;
			vis[x][y] = 1;
			pq.push({0, x, y});
			rep(i, 0, 4) {
				int nx = x+dx[i], ny = y+dy[i];
				if (outside(nx, ny)) continue;
				if (passable(x, y, nx, ny, H) == 0)
					q.push({nx, ny});
			}
		}
		vector<vi> dist(n, vi(m, -1));
		while (!pq.empty()) {
			auto [d,x,y] = pq.top(); pq.pop();
			if (dist[x][y] != -1) continue;
			dist[x][y] = d;
			int h = H-d;
			rep(i, 0, 4) {
				int nx = x+dx[i], ny = y+dy[i];
				if (outside(nx, ny)) continue;
				int pass = passable(x, y, nx, ny, h);
				if (pass == -1) continue;
				int w = lower[x][y]+20 <= h-pass ? 10 : 100;
				pq.push({d+w+pass, nx, ny});
			}
		}
		int res = dist[n-1][m-1];
		printf("Case #%d: %d.%d\n", t, res/10, res%10);
	}
}
