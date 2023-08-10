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
vi vis, dist, p1, p2;
vector<pii> dias;

int dfs(int v, int d, vi& vis, vi& p) {
	if (vis[v]) return -1;
	vis[v] = d;
	int res = v;
	for (int u : graph[v]) {
		if (!vis[u]) {
			p[u] = v;
			int k = dfs(u, d+1, vis, p);
			if (k != -1 && vis[k] > vis[res])
				res = k;
		}
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	graph.assign(n, {});
	rep(i, 0, m) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vis.assign(n, 0);
	dist.assign(n, 0);
	p1.assign(n, -1);
	p2.assign(n, -1);
	rep(i, 0, n) {
		if (!vis[i]) {
			int u = dfs(i, 1, vis, p1);
			int d = dfs(u, 1, dist, p2);
			int dia = dist[d]-1;
			while ((dist[d]-1) > dia/2) d = p2[d];
			dias.push_back({dia, d});
		}
	}
	sort(all(dias));
	int b = get<1>(dias.back());
	rep(i, 0, sz(dias)-1) {
		int a = get<1>(dias[i]);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vis.assign(n, 0);
	p1.assign(n, 0);
	int u = dfs(0, 1, vis, p1);
	vis.assign(n, 0);
	p1.assign(n, 0);
	int d = dfs(u, 1, vis, p1);
	printf("%d\n", vis[d]-1);
}
