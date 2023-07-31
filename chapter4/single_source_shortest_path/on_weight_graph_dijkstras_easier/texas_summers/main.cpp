#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef tuple<ll, ll, ll> iii;


ll n;
vector<pii> points;
vector<vector<pii>> graph;
vi dist, pre;

int main() {
	scanf("%lld", &n); n+=2;
	points.assign(n, pii());
	rep(i, 0, n) scanf("%lld%lld", &points[i].first, &points[i].second);
	graph.assign(n, vector<pii>());
	rep(i, 0, n) rep(j, i+1, n) {
		ll x = points[i].first-points[j].first;
		ll y = points[i].second-points[j].second;
		ll d = x*x+y*y;
		graph[i].push_back({j, d});
		graph[j].push_back({i, d});
	}
	dist.assign(n, -1);
	pre.assign(n, -1);
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({0, n-2, n-2});
	dist[n-2] = 0;
	while (!pq.empty()) {
		auto [d,v,p] = pq.top(); pq.pop();
		if (dist[v] < d) continue;
		dist[v] = d;
		pre[v] = p;
		for (auto [u,w] : graph[v])
			if (dist[u] == -1 || dist[u] > d+w)
				pq.push({d+w, u, v}),
				dist[u] = d+w;
	}
	vi res;
	ll v = n-1;
	while (pre[v] != -1 && pre[v] != n-2) {
		v = pre[v];
		res.push_back(v);
	}
	for (ll i = sz(res)-1; i >= 0; i--)
		printf("%lld\n", res[i]);
	if (!sz(res)) printf("-\n");
}
