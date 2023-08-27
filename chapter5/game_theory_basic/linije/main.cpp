#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll N = 500;

ll n;
vi match(N+1, -1), vis;
vector<vi> graph(N+1, vi());

ll mcbm(ll v) {
	if (vis[v]) return 0;
	vis[v] = 1;
	for (ll u : graph[v]) {
		if (match[u] == -1 || mcbm(match[u])) {
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	rep(i, 0, n) {
		ll x, y; cin >> x >> y;
		graph[x].push_back(y);
	}
	bool res = true;
	rep(v, 1, N+1) {
		if (sz(graph[v])) {
			vis.assign(N+1, 0);
			res &= mcbm(v);
		}
	}
	rep(v, 1, N+1)
		for (ll u : graph[v])
			res &= match[u] != -1;
	if (res) printf("Slavko\n");
	else printf("Mirko\n");
}
