#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct edge {
	int v,w;
};

int N;
vector<vector<edge>> graph;
vi T, deg;

int main() {
	scanf("%d", &N);
	graph.assign(N, vector<edge>());
	T.assign(N, 0);
	deg.assign(N, 0);
	rep(i, 0, N) {
		int k; scanf("%d%d", &T[i], &k);
		while (k--) {
			int s, v; scanf("%d%d", &s, &v); s--;
			graph[s].push_back({i, v});
			deg[i] += v;
		}
	}
	queue<int> q;
	vi vis(N, 0);
	q.push(0);
	vis[0] = 1;
	int res = N;
	while (!q.empty()) {
		res--;
		int v = q.front(); q.pop();
		for (auto [u,w] : graph[v]) {
			deg[u] -= w;
			if (deg[u] < T[u] && !vis[u])
				q.push(u), vis[u] = 1;
		}
	}
	printf("%d\n", res);
}
