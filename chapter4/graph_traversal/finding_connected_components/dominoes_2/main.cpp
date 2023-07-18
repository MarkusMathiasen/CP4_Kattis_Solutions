#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, n, m, l, res;
vector<vi> graph;
vi vis;

void dfs(int v) {
	vis[v] = 1;
	res++;
	for (int u : graph[v])
		if (!vis[u])
			dfs(u);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &l);
		graph.assign(n, vi());
		while (m--) {
			int a, b; scanf("%d%d", &a, &b); a--; b--;
			graph[a].push_back(b);
		}
		vis.assign(n, 0);
		res = 0;
		while (l--) {
			int z; scanf("%d", &z); z--;
			if (!vis[z])
				dfs(z);
		}
		printf("%d\n", res);
	}
}
