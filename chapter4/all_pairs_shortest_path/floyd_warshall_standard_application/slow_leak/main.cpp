#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

ll n, m, t, f;
vector<vector<ll>> dist;
vi vis, pumps;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> t >> f;
	dist.assign(n, vector<ll>(n, 1e18));
	rep(i, 0, n) dist[i][i] = 0;
	pumps.assign(t+2, -1);
	rep(i, 0, t) {cin >> pumps[i]; pumps[i]--;}
	pumps[t] = 0; pumps[t+1] = n-1;
	while (m--) {
		ll a, b, w; cin >> a >> b >> w; a--; b--;
		dist[a][b] = dist[b][a] = w;
	}
	rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
		dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	vis.assign(n, -1);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		auto [d,v] = pq.top(); pq.pop();
		if (vis[v] != -1) continue;
		vis[v] = d;
		for (ll u : pumps)
			if (dist[v][u] <= f)
				pq.push({d+dist[v][u], u});
	}
	if (vis[n-1] == -1) printf("stuck\n");
	else printf("%lld\n", vis[n-1]);
}
