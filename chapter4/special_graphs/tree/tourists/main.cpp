#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int p = 19;

int n;
vector<vi> graph, lift;
vi dist;

void dfs(int v, int d) {
	dist[v] = d;
	for (int u : graph[v]) {
		if (!lift[0][u]) {
			lift[0][u] = v;
			dfs(u, d+1);
		}
	}
}

int lca(int a, int b) {
	for (int i = p-1; i >= 0; i--) {
		if (dist[lift[i][a]] >= dist[b]) a = lift[i][a];
		if (dist[lift[i][b]] >= dist[a]) b = lift[i][b];
	}
	for (int i = p-1; i >= 0; i--)
		if (lift[i][a] != lift[i][b])
			a = lift[i][a], b = lift[i][b];
	if (a == b) return a;
	return lift[0][a];
}

ll ddist(int a, int b) {
	int c = lca(a, b);
	return dist[a] + dist[b] - 2*dist[c];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	graph.assign(n+1, {});
	rep(i, 0, n-1) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	lift.assign(p, vi(n+1, 0));
	lift[0][1] = 1;
	dist.assign(n+1, -1);
	dfs(1, 0);
	// fill out lift
	rep(i, 1, p) rep(j, 1, n+1)
		lift[i][j] = lift[i-1][lift[i-1][j]];
	ll res = 0;
	rep(i, 1, n+1) for (int j = 2*i; j <= n; j += i) {
		ll d = ddist(i, j) + 1;
		res += d;
	}
	printf("%lld\n", res);
}
