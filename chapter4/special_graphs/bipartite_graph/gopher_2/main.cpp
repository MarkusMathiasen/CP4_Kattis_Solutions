#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, m, s, v;
vector<vi> graph;
vector<pii> gophers, holes;
vi match, vis;

ll dist(ll a, ll b) {
	return (gophers[a].first-holes[b].first)*(gophers[a].first-holes[b].first)+(gophers[a].second-holes[b].second)*(gophers[a].second-holes[b].second);
}

ll mcbm(ll v, ll visi) {
	if (vis[v] == visi) return 0;
	vis[v] = visi;
	for (ll u : graph[v]) {
		if (match[u] == -1 || mcbm(match[u], visi)) {
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	while (scanf("%lld%lld%lld%lld", &n, &m, &s, &v) == 4) {
		graph.assign(n, {});
		gophers.assign(n, {0,0});
		holes.assign(n, {0,0});
		rep(i, 0, n) {
			ll a1, a2, b1, b2; scanf("%lld.%lld %lld.%lld", &a1, &a2, &b1, &b2);
			gophers[i].first = a1*10+a2;
			gophers[i].second = b1*10+b2;
		}
		rep(i, 0, m) {
			ll a1, a2, b1, b2; scanf("%lld.%lld %lld.%lld", &a1, &a2, &b1, &b2);
			holes[i].first = a1*10+a2;
			holes[i].second = b1*10+b2;
		}
		rep(i, 0, n) rep(j, 0, m)
			if (dist(i, j) <= s*v*10*s*v*10)
				graph[i].push_back(j);
		match.assign(n, -1);
		vis.assign(n, -1);
		ll res = 0;
		rep(i, 0, n) res += mcbm(i, i);
		printf("%lld\n", n-res);
	}
}
