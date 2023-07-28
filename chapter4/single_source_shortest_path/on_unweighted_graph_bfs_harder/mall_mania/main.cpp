#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int n = 2001;

int sgn(int x) {
	if (x < 0) return -1;
	return x > 0;
}

int main() {
	int p;
	vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
	while (scanf("%d", &p), p) {
		vector<vi> dist(n, vi(n, -1));
		vector<pii> m1(p, pii());
		rep(i, 0, p) scanf("%d%d", &m1[i].first, &m1[i].second);
		queue<pii> q;
		rep(i, 0, p) {
			auto [x1,y1] = m1[i];
			auto [x2,y2] = m1[(i+1)%p];
			while (x1 != x2 || y1 != y2) {
				dist[x1][y1] = 0;
				q.push({x1, y1});
				x1 += sgn(x2-x1), y1 += sgn(y2-y1);
			}
		}
		scanf("%d", &p);
		vector<pii> m2(p, pii());
		set<pii> goals;
		rep(i, 0, p) scanf("%d%d", &m2[i].first, &m2[i].second);
		rep(i, 0, p) {
			auto [x1,y1] = m2[i];
			auto [x2,y2] = m2[(i+1)%p];
			while (x1 != x2 || y1 != y2) {
				goals.insert({x1, y1});
				x1 += sgn(x2-x1), y1 += sgn(y2-y1);
			}
		}
		int res = 1e9;
		while (!q.empty()) {
			auto [x,y] = q.front(); q.pop();
			if (goals.count({x, y})) {
				res = dist[x][y];
				break;
			}
			rep(i, 0, 4) {
				int nx = x+dx[i], ny = y+dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[x][y]+1;
				q.push({nx, ny});
			}
		}
		printf("%d\n", res);
	}
}
