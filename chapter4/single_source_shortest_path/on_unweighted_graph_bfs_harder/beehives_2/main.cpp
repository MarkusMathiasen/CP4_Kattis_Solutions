#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;

int n, m;
vector<vi> graph;
vi dist;

int main() {
	scanf("%d%d", &n, &m);
	graph.assign(n, vi());
	while (m--) {
		int a, b; scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int res = inf;
	rep(start, 0, n) {
		dist.assign(n, -1);
		dist[start] = 0;
		vi p(n, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int u : graph[v]) {
				if (dist[u] == -1) {
					dist[u] = dist[v]+1;
					p[u] = v;
					q.push(u);
				}
				else if (p[v] != u)
					res = min(res, dist[u] + dist[v] + 1);
			}
		}
	}
	if (res == inf) printf("impossible\n");
	else printf("%d\n", res);
}
