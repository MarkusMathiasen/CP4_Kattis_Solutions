#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef tuple<ll, ll, ll> iii;

ll T;
ll N, M, L, S;
vector<vector<pii>> graph;
vi starts, vis;

int main() {
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld%lld%lld", &N, &M, &L, &S);
		starts.assign(S, 0);
		rep(i, 0, S) scanf("%lld", &starts[i]), starts[i]--;
		graph.assign(N, vector<pii>());
		while (M--) {
			ll a, b, w; scanf("%lld%lld%lld", &a, &b, &w); a--, b--;
			graph[a].push_back({b, w});
			graph[b].push_back({a, w});
		}
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		vis.assign(N, 0);
		for (ll x : starts) pq.push({0, x});
		ll res = 0;
		while (!pq.empty()) {
			auto [c,v] = pq.top(); pq.pop();
			if (vis[v]) continue;
			vis[v] = 1;
			res += c;
			for (auto [u,w] : graph[v])
				pq.push({w+L, u});
		}
		printf("%lld\n", res);
	}
}
