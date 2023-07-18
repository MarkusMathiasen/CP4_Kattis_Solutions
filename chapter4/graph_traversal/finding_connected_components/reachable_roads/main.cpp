#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, n, m;
vector<vi> graph;
vi vis;

void dfs(int v) {
	vis[v] = 1;
	for (int u : graph[v])
		if (!vis[u])
			dfs(u);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		graph.assign(n, vi());
		while (m--) {
			int a, b; scanf("%d%d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		vis.assign(n, 0);
		int res = 0;
		rep(i, 0, n)
			if (!vis[i])
				res++, dfs(i);
		printf("%d\n", res-1);
	}
}
