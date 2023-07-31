#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<vector<pii>> graph, pre;

int main() {
	scanf("%d%d", &n, &m);
	graph.assign(n, vector<pii>());
	pre.assign(n, vector<pii>());
	while (m--) {
		int a, b, w; scanf("%d%d%d", &a, &b, &w);
		graph[a].push_back({b, w});
		graph[b].push_back({a, w});
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 0});
	vi dist(n, -1);
	dist[0] = 0;
	while (!pq.empty()) {
		auto [d,v] = pq.top(); pq.pop();
		if (d > dist[v]) continue;
		for (auto [u,w] : graph[v]) {
			if (dist[u] == -1 || dist[u] > d+w) {
				dist[u] = d+w;
				pq.push({d+w, u});
				pre[u] = {{v, w}};
			} else if (dist[u] == d+w) {
				pre[u].push_back({v, w});
			}
		}
	}
	vi vis(n, 0);
	queue<int> q;
	q.push(n-1);
	int res = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto [u,w] : pre[v]) {
			res += w;
			q.push(u);
		}
	}
	printf("%d\n", res*2);
}
