#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vi A, topo, vis;
vector<vi> graph;

int calc(int zero) {
	vi dist(n, 0);
	for (int v : topo)
		for (int u : graph[v])
			dist[u] = max(dist[u], dist[v]+(v==zero ? 0 : A[v]));
	int res = 0;
	rep(i, 0, n) res = max(res, dist[i]+(i==zero ? 0 : A[i]));
	return res;
}

void toposort(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : graph[v])
		toposort(u);
	topo.push_back(v);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	A.assign(n, 0);
	rep(i, 0, n) cin >> A[i];
	graph.assign(n, vi());
	rep(i, 0, n) {
		int k; cin >> k;
		while (k--) {
			int j; cin >> j;
			graph[i].push_back(j-1);
		}
	}
	vis.assign(n, 0);
	toposort(n-1);
	reverse(all(topo));
	int res = 1e9;
	rep(i, 0, n) res = min(res, calc(i));
	printf("%d\n", res);
}
