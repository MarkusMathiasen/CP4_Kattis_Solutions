#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, m;
unordered_map<ll, ll> toi, ton;
vector<pii> pairs;
vector<vi> graph;
vi vis, match, rev_match;

ll mcbm(ll v, ll visi) {
	if (vis[v] == visi) return 0;
	vis[v] = visi;
	for (ll u : graph[v]) {
		if (match[u] == -1 || mcbm(match[u], visi)) {
			match[u] = v;
			rev_match[v] = u;
			return 1;
		}
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	graph.assign(n, {});
	rep(i, 0, n) {
		ll a, b; cin >> a >> b;
		pairs.push_back({a, b});
		vi ans = {a+b, a*b, a-b};
		for (ll c : ans) {
			if (!toi.count(c)) {
				ton[sz(toi)] = c;
				toi[c] = sz(toi);
			}
			graph[i].push_back(toi[c]);
		}
	}
	m = sz(toi);
	vis.assign(n, -1);
	match.assign(m, -1);
	rev_match.assign(n, -1);
	ll res = 0;
	rep(i, 0, n) res += mcbm(i, i);
	if (res == n) {
		rep(i, 0, n) {
			ll c = ton[rev_match[i]];
			auto [a,b] = pairs[i];
			char op;
			if (a + b == c) op = '+';
			else if (a - b == c) op = '-';
			else if (a * b == c) op = '*';
			else assert(false);
			printf("%lld %c %lld = %lld\n", a, op, b, c);
		}
	}
	else printf("impossible\n");
}
