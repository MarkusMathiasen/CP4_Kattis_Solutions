#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, cnt = 0;
vi tax, sub_tax, ddist, dist, dfs_num, p, p_dist, comp;
vector<vector<pii>> graph;

void dfs(ll v) {
	comp[v] = 1;
	sub_tax[v] = tax[v];
	for (auto [u,w] : graph[v]) {
		if (dfs_num[u]) continue;
		dfs_num[u] = ++cnt;
		p[u] = v;
		p_dist[u] = w;
		dfs(u);
		sub_tax[v] += sub_tax[u];
		dist[v] += dist[u] + comp[u]*w;
		ddist[v] += ddist[u] + sub_tax[u]*w;
		comp[v] += comp[u];
	}
}

int main() {
	// read input
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	tax.assign(n, 0);
	ll tax_sum = 0;
	rep(i, 0, n) {
		cin >> tax[i];
		tax_sum += tax[i];
	}
	graph.assign(n, {});
	rep(i, 0, n-1) {
		ll a, b, w; cin >> a >> b >> w; a--; b--;
		graph[a].push_back({b,w});
		graph[b].push_back({a,w});
	}
	// prepare dfs
	comp.assign(n, 0);
	sub_tax.assign(n, 0);
	dist.assign(n, 0);
	ddist.assign(n, 0);
	dfs_num.assign(n, 0);
	dfs_num[0] = ++cnt;
	p.assign(n, -1);
	p_dist.assign(n, -1);
	p[0] = p_dist[0] = 0;
	dfs(0);
	// dfs sort
	vi order(n, 0);
	rep(i, 0, n) order[i] = i;
	sort(all(order), [](const ll a, const ll b) {
		return dfs_num[a] < dfs_num[b];
	});
	// compute res
	vi res(n, 0);
	for (ll v : order) {
		dist[v] = dist[p[v]] + p_dist[v]*(n-2*comp[v]);
		ddist[v] = ddist[p[v]]+p_dist[v]*(tax_sum-2*sub_tax[v]);
		res[v] = ddist[v] + tax[v]*dist[v];
	}
	for (ll x : res) printf("%lld\n", x);
}
