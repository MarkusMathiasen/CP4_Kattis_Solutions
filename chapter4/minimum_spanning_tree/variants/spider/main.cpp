#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, m;
vi uf;
vector<vector<ll>> maxweight;
vector<vector<pii>> mst;

void dfs(ll v, ll start, ll w) {
	if (maxweight[start][v] != -1) return;
	maxweight[start][v] = w;
	for (auto [u,w2] : mst[v])
		dfs(u, start, max(w, w2));
}

ll find(ll v) {
	if (uf[v] == v) return v;
	return uf[v] = find(uf[v]);
}
bool issame(ll a, ll b) {return find(a) == find(b);}
void same(ll a, ll b) {uf[find(a)] = find(b);}

int main() {
	while (scanf("%lld%lld", &n, &m) == 2) {
		vector<tuple<ll,ll,ll>> edges;
		while (m--) {
			ll a,b, w; scanf("%lld%lld%lld", &a, &b, &w); a--; b--;
			edges.push_back({w, a, b});
		}
		uf.assign(n, 0);
		rep(i, 1, n) uf[i] = i;
		sort(all(edges));
		ll mst_w = 0;
		mst.assign(n, vector<pii>());
		ll cnt = 0;
		for (auto [w,a,b] : edges) {
			if (issame(a, b)) continue;
			same(a, b);
			mst_w += w;
			mst[a].push_back({b,w});
			mst[b].push_back({a,w});
			cnt++;
		}
		if (cnt != n-1) {
			printf("disconnected\n");
			continue;
		}
		maxweight.assign(n, vi(n, -1));
		rep(i, 0, n) dfs(i, i, 0);
		rep(i, 0, n) rep(j, 0, n) assert(maxweight[i][j] != -1);
		ll res = mst_w;
		for (auto [w,a,b] : edges)
			res = min(res, mst_w-maxweight[a][b]-w);
		printf("%lld\n", res);
	}
}
