#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct edge {
	int v, t0, P, d;
};

int n, m, q, s;
vector<vector<edge>> graph;

int main() {
	while (scanf("%d%d%d%d", &n, &m, &q, &s), n || m || q || s) {
		graph.assign(n, vector<edge>());
		while (m--) {
			int a, b, t0, P, d; scanf("%d%d%d%d%d", &a, &b, &t0, &P, &d);
			graph[a].push_back({b, t0, P, d});
		}
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.push({0, s});
		vi dist(n, -1);
		while (!pq.empty()) {
			auto [d,v] = pq.top(); pq.pop();
			if (dist[v] != -1) continue;
			dist[v] = d;
			for (auto [u,t0,P,w] : graph[v]) {
				if (t0 >= d)
					pq.push({t0+w, u});
				else if (P != 0) {
					int t = (d-t0)/P + !!((d-t0)%P);
					pq.push({t0+t*P+w, u});
				}
			}
		}
		while (q--) {
			int v; scanf("%d", &v);
			if (dist[v] == -1) printf("Impossible\n");
			else printf("%d\n", dist[v]);
		}
		printf("\n");
	}

}
