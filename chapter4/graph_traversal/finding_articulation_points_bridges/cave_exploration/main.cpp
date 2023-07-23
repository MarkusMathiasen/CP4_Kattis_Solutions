#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, M, cnt=0, res = 0;
vector<vi> graph;
set<pii> bridges;
vi num, low, p, vis;

void find_bridges(int v) {
	num[v] = low[v] = ++cnt;
	for (int u : graph[v]) {
		if (p[v] == u) continue;
		if (!num[u]) {
			p[u] = v;
			find_bridges(u);
			if (num[v] < low[u])
				bridges.insert({v, u}),
				bridges.insert({u, v});
		}
		low[v] = min(low[v], low[u]);
	}
}

void count(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	res++;
	for (int u : graph[v]) {
		if (bridges.count({v, u})) continue;
		count(u);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	graph.assign(N, vi());
	num.assign(N, 0);
	low.assign(N, 0);
	p.assign(N, -1);
	vis.assign(N, 0);
	while (M--) {
		int a, b; scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	find_bridges(0);
	count(0);
	printf("%d\n", res);
}
