#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> iii;

int T, n, Q, s, t, k;
vector<vector<pii>> graph;
vector<vi> dist;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		graph.assign(n, {});
		rep(v, 0, n) {
			int k; cin >> k;
			while (k--) {
				int u, w; cin >> u >> w;
				graph[v].push_back({u, w});
			}
		}
		cin >> Q;
		while (Q--) {
			cin >> s >> t >> k;
			dist.assign(k, vi(n, 1e9));
			dist[k-1][s] = 0;
			for (int i = k-1; i > 0; i--)
				rep(v, 0, n)
					for (auto [u,w] : graph[v])
						dist[i-1][u] = min(dist[i-1][u], dist[i][v]+w);
			int res = 1e9;
			rep(i, 0, k) res = min(res, dist[i][t]);
			printf("%d\n", res == 1e9 ? -1 : res);
		}
		printf("\n");
	}
}
