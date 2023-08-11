#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
bool valid = true;
vector<vi> grid, graph;
vector<set<int>> cols;
vi match, vis;

int mcbm(int v, int visi) {
	if (vis[v] == visi) return 0;
	vis[v] = visi;
	for (int u : graph[v]) {
		if (match[u] == -1 || mcbm(match[u], visi)) {
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	// Read input
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	grid.assign(n, vi(n, 0));
	rep(i, 0, k) rep(j, 0, n) {
		cin >> grid[i][j];
		grid[i][j]--;
	}
	// Validate input
	rep(i, 0, k) {
		unordered_set<int> s;
		rep(j, 0, n) s.insert(grid[i][j]);
		valid &= sz(s) == n;
	}
	cols.assign(n, set<int>());
	rep(j, 0, n) {
		rep(i, 0, k) cols[j].insert(grid[i][j]);
		valid &= sz(cols[j]) == k;
	}
	if (!valid) {
		printf("no\n");
		return 0;
	}
	printf("yes\n");
	// Fill superdoku
	rep(i, k, n) {
		graph.assign(n, {});
		rep(col, 0, n) rep(num, 0, n)
			if (!cols[col].count(num))
				graph[num].push_back(col);
		match.assign(n, -1);
		vis.assign(n, -1);
		rep(j, 0, n) mcbm(j, j);
		rep(j, 0, n) {
			grid[i][j] = match[j];
			cols[j].insert(match[j]);
		}
	}
	rep(i, 0, n) {
		rep(j, 0, n) printf("%d ", grid[i][j]+1);
		printf("\n");
	}
}
