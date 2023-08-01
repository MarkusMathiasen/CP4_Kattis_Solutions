#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, f, n;
vi fire, dist, dist2;
vector<vector<pii>> graph;

void dijkstra(int start, vi& dist) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<bool> vis(n, 0);
	pq.push({0, start});
	dist[start] = 0;
	while (!pq.empty()) {
		auto [d,v] = pq.top(); pq.pop();
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto [u,w] : graph[v])
			if (dist[u] > d+w)
				pq.push({d+w, u}),
				dist[u] = d+w;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> f >> n;
		fire.assign(f, 0);
		rep(i, 0, f) {cin >> fire[i]; fire[i]--;}
		string line; getline(cin, line);
		graph.assign(n, vector<pii>());
		while (getline(cin, line) && line != "") {
			stringstream ss(line);
			int a, b, w; ss >> a >> b >> w; a--, b--;
			graph[a].push_back({b, w});
			graph[b].push_back({a, w});
		}
		dist.assign(n, 1e9);
		rep(i, 0, f) dijkstra(fire[i], dist);
		dist2.assign(all(dist));
		int res = 0, val = 1e9;
		rep(i, 0, n) {
			if (dist[i]) {
				dijkstra(i, dist2);
				int v = 0;
				rep(i, 0, n) {
					v = max(v, dist2[i]);
					dist2[i] = dist[i];
				}
				if (v < val)
					val = v, res = i;
			}
		}
		printf("%d\n", res+1);
	}
}
