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
vi in_deg, out_deg, res, vis, idx;

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : graph[v])
		dfs(u);
}

void euler(int v) {
	while (idx[v] < sz(graph[v])) {
		int u = graph[v][idx[v]++];
		euler(u);
		res.push_back(v);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n >> m), n || m) {
		// Read input
		graph.assign(n, {});
		in_deg.assign(n, 0);
		out_deg.assign(n, 0);
		while (m--) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			out_deg[a]++;
			in_deg[b]++;
		}
		// Check if eulerian
		int start = -1, goal = -1;
		bool possible = true;
		rep(i, 0, n) {
			if (in_deg[i] == out_deg[i]) continue;
			else if (in_deg[i]+1 == out_deg[i] && start == -1) start = i;
			else if (in_deg[i] == out_deg[i]+1 && goal == -1) goal = i;
			else possible = false;
		}
		if (start == -1) rep(i, 0, n) if (sz(graph[i])) start = goal = i;
		vis.assign(n, 0);
		dfs(start);
		rep(i, 0, n) possible &= !sz(graph[i]) || vis[i];
		if (!possible) {
			printf("Impossible\n");
			continue;
		}
		// Euler tour
		res = {goal};
		idx.assign(n, 0);
		euler(start);
		reverse(all(res));
		for (int x : res) printf("%d ", x);
		printf("\n");
	}
}
