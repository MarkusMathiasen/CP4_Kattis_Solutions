#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int A, B, n, m;
vector<vi> graph, trans;
vi before, after, vis;

int dfs(int v, vector<vi>& graph) {
	if (vis[v]) return 0;
	vis[v] = 1;
	int res = 1;
	for (int u : graph[v])
		res += dfs(u, graph);
	return res;
}

int main() {
	scanf("%d%d%d%d", &A, &B, &n, &m);
	graph.assign(n, vi());
	trans.assign(n, vi());
	while (m--) {
		int a, b; scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		trans[b].push_back(a);
	}
	before.assign(n, 0);
	after.assign(n, 0);
	rep(i, 0, n) {
		vis.assign(n, 0);
		after[i] = dfs(i, graph);
	}
	rep(i, 0, n){
		vis.assign(n, 0);
		before[i] = dfs(i, trans);
	}
	int certainA = 0, certainB = 0, noB = 0;
	rep(i, 0, n) {
		if (after[i] > n-A)
			certainA++;
		if (after[i] > n-B)
			certainB++;
		if (before[i] > B)
			noB++;
	}
	printf("%d\n%d\n%d\n", certainA, certainB, noB);
}
