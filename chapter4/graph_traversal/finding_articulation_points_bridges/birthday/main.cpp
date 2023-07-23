#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, cnt, res;
vector<vi> graph;
vi num, low, p;

void dfs(int v) {
	low[v] = num[v] = ++cnt;
	for (int u : graph[v]) {
		if (p[v] == u) continue;
		if (!num[u]) {
			p[u] = v;
			dfs(u);
		}
		low[v] = min(low[v], low[u]);
		res |= low[u] > num[v];
	}
}

int main() {
	while (scanf("%d%d", &n, &m), n && m) {
		graph.assign(n, vi());
		num.assign(n, 0);
		low.assign(n, 0);
		p.assign(n, -1);
		res = cnt = 0;
		while (m--) {
			int a, b; scanf("%d%d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(0);
		rep(i, 0, n) res |= num[i] == 0;
		printf(res ? "Yes\n" : "No\n");
	}
}
