#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAX = 1e18;

ll n, m;
vector<vi> graph;
vi dist, h, order;

unordered_set<ll> fibs;
map<ll, vector<ll>> idx;
unordered_map<ll, ll> next_fib;
void compute_fibs() {
	ll a = 1, b = 1;
	while (b < MAX) {
		next_fib[a] = b;
		fibs.insert(b);
		ll t = b;
		b += a;
		a = t;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	compute_fibs();
	h.assign(n, -1);
	dist.assign(n, 0);
	rep(i, 0, n) {
		cin >> h[i];
		if (fibs.count(h[i]))
			idx[h[i]].push_back(i),
			dist[i] = 1;
	}
	graph.assign(n, vi());
	while (m--) {
		ll a, b; cin >> a >> b; a--; b--;
		if (next_fib[h[a]]==h[b]) graph[a].push_back(b);
		if (next_fib[h[b]]==h[a]) graph[b].push_back(a);
		if (h[a] == 1 && h[b] == 1) dist[a] = dist[b] = 2;
	}
	rep(v, 0, n) if (h[v] == 1LL) {
		dist[v] = max(dist[v], 1LL);
		for (ll u : graph[v])
			if (h[u] == 1)
				dist[u] = 2;
	}
	for (auto& [f,A] : idx)
		for (ll v : A)
			for (ll u : graph[v])
				dist[u] = max(dist[u], dist[v]+1);
	ll res = 0;
	for (ll x : dist) res = max(res, x);
	printf("%lld\n", res);
}
