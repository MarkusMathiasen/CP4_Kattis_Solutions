#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<vi> graph;
vi forced, stopping;
vector<vi> vis;

void dfs(int v, int s) {
	if (vis[v][s]) return;
	vis[v][s] = 1;
	if (forced[v] == -1)
		stopping[v] = 1;
	else
		dfs(forced[v], s);
	if (s)
		for (int u : graph[v])
			dfs(u, 0);
}

int main() {
	scanf("%d%d", &n, &m);
	graph.assign(n, vi());
	forced.assign(n, -1);
	while (m--) {
		int a, b; scanf("%d%d", &a, &b); a--, b--;
		if (a < 0)
			forced[-a-2] = b;
		else
			graph[a].push_back(b);
	}
	stopping.assign(n, 0);
	vis.assign(n, vi(2, 0));
	dfs(0, 1);
	int res = 0;
	for (int x : stopping) res += x;
	printf("%d\n", res);
}
