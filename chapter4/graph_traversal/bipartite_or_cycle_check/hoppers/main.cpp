#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, M, comps = 0;
vector<vi> graph;
vi leaders, vis, color;

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : graph[v])
		dfs(u);
}

int main() {
	scanf("%d%d", &N, &M);
	graph.assign(N, vi());
	while (M--) {
		int a, b; scanf("%d%d", &a, &b); a--, b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vis.assign(N, 0);
	rep(i, 0, N) {
		if (!vis[i]) {
			comps++;
			leaders.push_back(i);
			dfs(i);
		}
	}
	rep(i, 1, sz(leaders))
		graph[0].push_back(leaders[i]),
		graph[leaders[i]].push_back(0);
	queue<int> q; // vertex + color
	color.assign(N, 0);
	bool bipartite = true;
	q.push(0);
	color[0] = 1;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int u : graph[v]) {
			if (!color[u]) {
				color[u] = -color[v];
				q.push(u);
			} else if (color[u] == color[v]) {
				bipartite = false;
			}
		}
	}
	printf("%d\n", comps-1+bipartite);
}
