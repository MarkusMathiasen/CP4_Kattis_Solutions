#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> iii;

int n, k;
vector<vi> grid, dist;

int main() {
	scanf("%d%d", &n, &k);
	grid.assign(n, vi(n, -1));
	dist.assign(n, vi(n, -1));
	rep(i, 0, n) rep(j, 0, n) scanf("%d", &grid[i][j]);
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	rep(i, 0, n) rep(j, 0, n) if (grid[i][j] == 1) pq.push({0, i, j});
	while (!pq.empty()) {
		auto [d,x,y] = pq.top(); pq.pop();
		if (dist[x][y] != -1) continue;
		dist[x][y] = d;
		rep(i, 0, n) rep(j, 0, n)
			if (grid[i][j] == grid[x][y]+1)
				pq.push({d+abs(i-x)+abs(j-y), i, j});
	}
	int res = 1e9;
	rep(i, 0, n) rep(j, 0, n)
		if (grid[i][j] == k)
			res = min(res, dist[i][j]);
	if (res == 1e9) printf("-1");
	else printf("%d\n", res);
}
