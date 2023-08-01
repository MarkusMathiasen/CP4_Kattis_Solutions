#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
int start, goal, K, G;
vector<vector<pii>> graph;
vi route;
map<pii, pii> locked;

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d%d%d", &start, &goal, &K, &G); start--, goal--;
	graph.assign(n, vector<pii>());
	route.assign(G, 0);
	rep(i, 0, G) scanf("%d", &route[i]), route[i]--;
	rep(i, 0, G-1) {
		int a = route[i], b = route[i+1];
		locked[{a,b}] = {-1, -1};
		locked[{b,a}] = {-1, -1};
	}
	while (m--) {
		int a, b, w; scanf("%d%d%d", &a, &b, &w); a--; b--;
		graph[a].push_back({b, w});
		graph[b].push_back({a, w});
		if (locked.count({a,b})) {
			locked[{a,b}].second = w;
			locked[{b,a}].second = w;
		}
	}
	locked[{route[0], route[1]}].first = 0;
	locked[{route[1], route[0]}].first = 0;
	rep(i, 1, G-1) {
		pii& a = locked[{route[i], route[i+1]}];
		pii& b = locked[{route[i+1], route[i]}];
		a.first = b.first = locked[{route[i-1], route[i]}].second;
		a.second = b.second = a.first+a.second;
	}
	/*
	rep(i, 0, G-1) {
		int a = route[i], b = route[i+1];
		printf("(%d, %d) = [%d, %d]\n",
			a, b, locked[{a,b}].first, locked[{a,b}].second);
	}
	*/
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({K, start});
	vi dist(n, -1);
	while (!pq.empty()) {
		auto [d,v] = pq.top(); pq.pop();
		if (dist[v] != -1) continue;
		dist[v] = d;
		for (auto [u,w] : graph[v]) {
			if (locked.count({v,u})) {
				auto [a,b] = locked[{v,u}];
				if (d < a || d >= b) pq.push({d+w, u});
				else pq.push({b+w, u});
			} else
				pq.push({d+w, u});
		}
	}
	printf("%d\n", dist[goal]-K);
}
