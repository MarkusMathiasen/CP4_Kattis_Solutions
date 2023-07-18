#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<vi> graph, trans;
vi order;
vi vis;

void dfs(int v, vector<vi>& g) {
	vis[v] = 1;
	for (int u : g[v])
		if (!vis[u])
			dfs(u, g);
}

int main() {
	scanf("%d", &n);
	graph.assign(1001, vi());
	trans.assign(1001, vi());
	rep(i, 0, n) {
		int v, k; scanf("%d%d", &v, &k);
		order.push_back(v);
		while (k--) {
			int u; scanf("%d", &u);
			graph[v].push_back(u);
			trans[u].push_back(v);
		}
	}
	bool no = true;
	vis.assign(1001, 0);
	dfs(0, trans);
	for (int x : order)
		if (!vis[x])
			printf("TRAPPED %d\n", x),
			no = false;
	vis.assign(1001, 0);
	dfs(0, graph);
	for (int x : order)
		if (!vis[x])
			printf("UNREACHABLE %d\n", x),
			no = false;
	if (no)
		printf("NO PROBLEMS\n");
}
