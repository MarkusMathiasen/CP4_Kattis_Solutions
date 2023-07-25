#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<vi> graph1, graph2;
set<pii> vis;

void read_graph(vector<vi>& graph) {
	graph.assign(n, vi(4, 0));
	rep(i, 0, n) rep(j, 0, 4) {
		scanf("%d", &graph[i][j]);
		graph[i][j]--;
	}
}

void dfs(int a, int b) {
	if (vis.count({a, b})) return;
	vis.insert({a, b});
	rep(d, 0, 4) {
		if (graph1[a][d] == -1) continue;
		int a2 = graph1[a][d];
		int b2 = b == -1 ? -1 : graph2[b][d];
		dfs(a2, b2);
	}
}

int main() {
	scanf("%d", &n);
	read_graph(graph1);
	read_graph(graph2);
	dfs(0, 0);
	bool impossible = true;
	bool yes = true;
	for (auto [a,b] : vis) {
		if (a == n-1) {
			impossible = false;
			if (b != n-1)
				yes = false;
		}
	}
	if (impossible) printf("Impossible\n");
	else if (yes) printf("Yes\n");
	else printf("No\n");
}
