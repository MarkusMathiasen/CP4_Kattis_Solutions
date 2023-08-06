#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<vi> graph;
vi A, dist, changed, vis;

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : graph[v])
		dfs(u);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n) {
		if (n == -1) break;
		graph.assign(n, vi());
		A.assign(n, 0);
		rep(i, 0, n) {
			int v, k; cin >> v >> k;
			A[i] = v;
			while (k--) {
				int j; cin >> j;
				graph[i].push_back(j-1);
			}
		}
		dist.assign(n, 0);
		dist[0] = 100;
		rep(round, 0, n) {
			changed.assign(n, 0);
			rep(i, 0, n)
				if (dist[i] > 0)
					for (int j : graph[i])
						if (dist[j] < dist[i]+A[j])
							dist[j] = dist[i]+A[j],
							changed[j] = 1;
		}
		vis.assign(n, 0);
		rep(i, 0, n) if (changed[i]) dfs(i);
		if (dist[n-1] > 0 || vis[n-1]) printf("winnable\n");
		else printf("hopeless\n");
	}
}
