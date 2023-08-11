#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, res = 0;
vector<vi> graph;
vi vis, match;

int mcbm(int v) {
	if (vis[v]) return 0;
	vis[v] = 1;
	for (int u : graph[v]) {
		if (match[u] == -1 || mcbm(match[u])) {
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	graph.assign(n, {});
	while (m--) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
	}
	match.assign(n, -1);
	rep(i, 0, n)
		vis.assign(n, 0),
		res += mcbm(i);
	printf(res == n ? "YES\n" : "NO\n");
}
