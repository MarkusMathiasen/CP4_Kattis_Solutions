#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, m, s, t, cnt = 0;
vector<vector<pii>> graph;
vi sdist, tdist;
vi p, num, low, art;

void dijkstra(ll start, vi& dist) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, start);
	while (!pq.empty()) {
		auto [d,v] = pq.top(); pq.pop();
		if (dist[v] != -1) continue;
		dist[v] = d;
		for (auto [u,w] : graph[v])
			pq.emplace(d+w, u);
	}
}

void dfs(ll v) {
	num[v] = low[v] = ++cnt;
	for (auto [u,w] : graph[v]) {
		if (p[v] == u || sdist[u] + tdist[u] != sdist[t]) continue;
		if (!num[u]) {
			p[u] = v;
			dfs(u);
			low[v] = min(low[v], low[u]);
			if (low[u] >= num[v]) art[v] = 1;
		}
		else {
			low[v] = min(low[v], num[u]);
		}
	}
}

int main() {
	scanf("%lld%lld", &n, &m);
	graph.assign(n, vector<pii>());
	while (m--) {
		ll a, b, w; scanf("%lld%lld%lld", &a, &b, &w);
		graph[a].emplace_back(b, w);
		graph[b].emplace_back(a, w);
	}
	scanf("%lld%lld", &s, &t);
	// Compute distances
	sdist.assign(n, -1);
	tdist.assign(n, -1);
	dijkstra(t, tdist);
	dijkstra(s, sdist);
	assert(sdist[t] == tdist[s]);
	// Find articulation points
	p.assign(n, -1);
	num.assign(n, 0);
	low.assign(n, 0);
	art.assign(n, 0);
	dfs(s);
	art[s] = art[t] = 1;
	// Print solution;
	rep(i, 0, n) if (art[i]) printf("%d ", i);
	printf("\n");

}
