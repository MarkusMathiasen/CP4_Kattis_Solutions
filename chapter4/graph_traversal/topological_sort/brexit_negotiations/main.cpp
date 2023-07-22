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
vi len, unl, deg, topo;

void dfs_unl(int v, int l) {
	if (unl[v]) return;
	unl[v] = l;
	for (int u : trans[v])
		dfs_unl(u, l);
}

int main() {
	scanf("%d", &n);
	graph.assign(n, vi());
	trans.assign(n, vi());
	len.assign(n, 0);
	deg.assign(n, 0);
	rep(i, 0, n) {
		scanf("%d%d", &len[i], &deg[i]);
		rep(j, 0, deg[i]) {
			int x; scanf("%d", &x); x--;
			graph[x].push_back(i);
			trans[i].push_back(x);
		}
	}
	vi order(n, 0);
	rep(i, 1, n) order[i] = i;
	sort(all(order), [](const int a, const int b) {
		return len[a] > len[b];
	});
	unl.assign(n, 0);
	rep(i, 0, n) dfs_unl(order[i], len[order[i]]);
	priority_queue<pii> pq;
	rep(i, 0, n)
		if (deg[i] == 0)
			pq.push({unl[i], i});
	while (!pq.empty()) {
		auto [z,v] = pq.top(); pq.pop();
		topo.push_back(v);
		for (int u : graph[v]) {
			deg[u]--;
			if (deg[u] == 0)
				pq.push({unl[u], u});
		}
	}
	int res = 0;
	rep(i, 0, n)
		res = max(res, i+len[topo[i]]);
	printf("%d\n", res);
}
