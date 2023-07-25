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
vi res, vis;

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : graph[v])
		dfs(u);
	res.push_back(v);
}

int main() {
	scanf("%d", &n);
	graph.assign(n, vi());
	rep(i, 0, n) rep(j, 0, n) {
		char c; scanf(" %c", &c);
		if (c == '1') graph[i].push_back(j);
	}
	vis.assign(n, 0);
	dfs(0);
	if (sz(res) != n) {
		printf("impossible\n");
		return 0;
	}
	for (int x : res) printf("%d ", x);
	printf("\n");
}
