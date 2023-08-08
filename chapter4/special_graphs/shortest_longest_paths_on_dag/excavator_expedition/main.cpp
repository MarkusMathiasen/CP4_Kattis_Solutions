#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
string s;
vi A, topo, vis, dist;
vector<vi> graph;

void toposort(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : graph[v])
		toposort(u);
	topo.push_back(v);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> s;
	A.assign(n, 0);
	rep(i, 1, n-1) A[i] = s[i] == 'X' ? 1 : -1;
	graph.assign(n, vi());
	while (m--) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
	}
	vis.assign(n, 0);
	toposort(0);
	reverse(all(topo));
	dist.assign(n, -1e9);
	dist[0] = 0;
	for (int v : topo)
		for (int u : graph[v])
			dist[u] = max(dist[u], dist[v]+A[u]);
	printf("%d\n", dist[n-1]);
}
