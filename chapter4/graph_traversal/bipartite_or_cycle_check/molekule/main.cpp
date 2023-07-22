#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N;
vector<vi> graph;
vi color;
vector<pii> edges;

int main() {
	scanf("%d", &N);
	graph.assign(N, vi());
	rep(i, 0, N-1) {
		int a, b; scanf("%d%d", &a, &b); a--, b--;
		edges.push_back({a, b});
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	queue<int> q;
	color.assign(N, 0);
	q.push(0);
	color[0] = 1;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int u : graph[v]) {
			if (!color[u]) {
				color[u] = -color[v];
				q.push(u);
			}
		}
	}
	for (auto [a,b] : edges)
		printf("%d\n", color[a] < color[b]);
}
