#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, q, s;
vector<vector<pii>> graph;

int main() {
	while (scanf("%d%d%d%d", &n, &m, &q, &s), n || m || q || s) {
		graph.assign(n, vector<pii>());
		while (m--) {
			int a, b, w; scanf("%d%d%d", &a, &b, &w);
			graph[a].push_back({b, w});
		}
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.push({0, s});
		vi dist(n, -1);
		while (!pq.empty()) {
			auto [d,v] = pq.top(); pq.pop();
			if (dist[v] != -1) continue;
			dist[v] = d;
			for (auto [u,w] : graph[v])
				pq.push({d+w,u});
		}
		while (q--) {
			int v; scanf("%d", &v);
			if (dist[v] == -1) printf("Impossible\n");
			else printf("%d\n", dist[v]);
		}
		printf("\n");
	}
}
