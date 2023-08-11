#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, c;
vector<vector<pii>> graph;
vi vis;

int dfs(int v) {
	vis[v] = 1;
	int res = 0;
	for (auto [u,w] : graph[v]) {
		if (vis[u]) continue;
		res += min(dfs(u), w);
	}
	return res ? res : (int)1e9;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n >> c) { c--;
		graph.assign(n, {});
		rep(i, 0, n-1) {
			int u, v, w; cin >> u >> v >> w; u--; v--;
			graph[u].push_back({v,w});
			graph[v].push_back({u,w});
		}
		vis.assign(n, 0);
		int res = dfs(c);
		printf("%d\n", res);
	}
}
