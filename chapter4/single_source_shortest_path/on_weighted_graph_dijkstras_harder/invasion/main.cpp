#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, A, K;
vector<vector<pii>> graph;
vi dist, vis;
int res;

void dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, start});
	res -= dist[start] == -1;
	dist[start] = 0;
	vis.assign(n, 0);
	while (!pq.empty()) {
		auto [d,v] = pq.top(); pq.pop();
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto [u,w] : graph[v])
			if (d+w < K && (dist[u] == -1 || dist[u] > d+w))
				res -= dist[u] == -1,
				dist[u] = d+w,
				pq.push({d+w, u});
	}
}

int main() {
	while (scanf("%d%d%d%d", &n, &m, &A, &K), n||m||A||K) {
		graph.assign(n, vector<pii>());
		while (m--) {
			int a, b, w; scanf("%d%d%d", &a, &b, &w); a--, b--;
			graph[a].push_back({b,w});
			graph[b].push_back({a,w});
		}
		dist.assign(n, -1);
		res = n;
		while (A--) {
			int a; scanf("%d", &a); a--;
			dijkstra(a);
			printf("%d\n", res);
		}
		printf("\n");
	}
}
