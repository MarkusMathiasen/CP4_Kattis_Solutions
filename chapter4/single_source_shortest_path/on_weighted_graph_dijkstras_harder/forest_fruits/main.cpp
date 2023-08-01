#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, m, C, K, M;
vector<vector<pii>> graph;
vi clears, dist, res;

int main() {
	scanf("%lld%lld%lld%lld%lld", &n, &m, &C, &K, &M);
	graph.assign(n, vector<pii>());
	while (m--) {
		ll a, b, w; scanf("%lld%lld%lld", &a, &b, &w); a--, b--;
		graph[a].push_back({b, w});
		graph[b].push_back({a, w});
	}
	clears.assign(C, -1);
	rep(i, 0, C) scanf("%lld", &clears[i]), clears[i]--;
	dist.assign(n, -1);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		auto [d,v] = pq.top(); pq.pop();
		if (dist[v] != -1) continue;
		dist[v] = d;
		for (auto [u,w] : graph[v])
			pq.push({d+w,u});
	}
	for (ll c : clears) if (dist[c] != -1) res.push_back(dist[c]);
	if (K > sz(res) && M > sz(res)) {
		printf("-1\n");
		return 0;
	}
	sort(all(res));
	printf("%lld\n", 2*res[min(K,M)-1]);
}
