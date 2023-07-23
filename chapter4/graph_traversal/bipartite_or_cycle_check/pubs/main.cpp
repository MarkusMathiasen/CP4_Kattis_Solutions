#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<vi> graph;
vi color;

int main() {
	scanf("%d%d", &n, &m);
	graph.assign(n, vi());
	color.assign(n, 0);
	while (m--) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	rep(i, 0, n) if (!sz(graph[i])){
		printf(" Impossible\n");
		return 0;
	}
	queue<int> q;
	rep(i, 0, n) {
		if (!color[i]) {
			color[i] = 1;
			q.push(i);
			while (!q.empty()) {
				int v = q.front(); q.pop();
				for (int u : graph[v]) {
					if (!color[u]) {
						color[u] = -color[v];
						q.push(u);
					}
				}
			}
		}
	}
	for (int c : color)
		printf(c == 1 ? "pub " : "house ");
	printf("\n");
}
