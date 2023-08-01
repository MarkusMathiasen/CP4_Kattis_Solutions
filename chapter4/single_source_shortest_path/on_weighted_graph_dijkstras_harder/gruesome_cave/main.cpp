#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<long double, int, int> dii;

int n, m;
vector<string> grid;
vector<vi> neigh;
vector<vector<long double>> prob, prob2, avg;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	grid.assign(n, "");
	string line; getline(cin, line);
	rep(i, 0, n) getline(cin, grid[i]);
	neigh.assign(n, vi(m, 0));
	rep(i, 1, n-1) rep(j, 1, m-1) if (grid[i][j] == ' ') {
		rep(k, 0, 4) neigh[i][j] += grid[i+dx[k]][j+dy[k]] == ' ';
	}
	int spaces = 0;
	rep(i, 0, n) rep(j, 0, m) spaces += grid[i][j] == ' ';
	prob.assign(n, vector<long double>(m, 0));
	rep(i, 0, n) rep(j, 0, m)
		if (grid[i][j] == ' ')
			prob[i][j] = 1.0L/spaces;
	const int stable_itt = 30000;
	rep(itteration, 0, stable_itt) {
		prob2.assign(n, vector<long double>(m, 0));
		rep(i, 1, n-1) rep(j, 1, m-1)
			if (grid[i][j] == ' ') {
				rep(k, 0, 4) {
					int ni = i+dx[k], nj = j+dy[k];
					if (grid[ni][nj] == ' ')
						prob2[i][j] += prob[ni][nj]/neigh[ni][nj];
				}
			}
		prob.assign(all(prob2));
	}
	avg.assign(n, vector<long double>(m, 0));
	const int avg_itt = 20000;
	rep(itteration, 0, avg_itt) {
		prob2.assign(n, vector<long double>(m, 0));
		rep(i, 1, n-1) rep(j, 1, m-1)
			if (grid[i][j] == ' ') {
				rep(k, 0, 4) {
					int ni = i+dx[k], nj = j+dy[k];
					if (grid[ni][nj] == ' ')
						prob2[i][j] += prob[ni][nj]/neigh[ni][nj];
				}
			}
		prob.assign(all(prob2));
		rep(i, 1, n-1) rep(j, 1, m-1)
			avg[i][j] += prob[i][j]/avg_itt;
	}
	// Dijkstra
	vector<vector<long double>> dist(n, vector<long double>(m, -1));
	int sx, sy, gx, gy;
	rep(i, 0, n) rep(j, 0, m)
		if (grid[i][j] == 'E') sx = i, sy = j;
		else if (grid[i][j] == 'D') gx = i, gy = j;
	priority_queue<dii, vector<dii>, greater<dii>> pq;
	pq.push({0, sx, sy});
	while (!pq.empty()) {
		auto [d,x,y] = pq.top(); pq.pop();
		if (dist[x][y] != -1) continue;
		dist[x][y] = d;
		rep(i, 0, 4) {
			int nx = x+dx[i], ny = y+dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (grid[nx][ny] == '#') continue;
			pq.push({d+avg[nx][ny], nx, ny});
		}
	}
	printf("%Lf\n", dist[gx][gy]);
}
