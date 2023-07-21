#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<vi> grid, graph;
vi vis;

int dfs(int v) {
	if (vis[v]) return 0;
	vis[v] = 1;
	int res = 1;
	for (int u : graph[v])
		res += dfs(u);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n >> m;
	grid.assign(n, vi(n, 0));
	rep(i, 0, m) {
		int p; string s; cin >> p >> s;
		rep(a, 0, n) rep(b, a+1, n) {
			int A = s[a]-'A', B = s[b]-'A';
			grid[A][B] += p;
			grid[B][A] -= p;
		}
	}
	graph.assign(n, vi());
	rep(i, 0, n) rep(j, i+1, n) {
		if (grid[i][j] > 0)
			graph[i].push_back(j);
		else
			graph[j].push_back(i);
	}
	rep(i, 0, n) {
		printf("%c: ", i+'A');
		vis.assign(n, 0);
		int v = dfs(i);
		if (v == n) printf("can win\n");
		else printf("can't win\n");
	}
}
