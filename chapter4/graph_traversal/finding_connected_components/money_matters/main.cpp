#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, cnt = 1;
vi o, comp;
vector<vi> graph;

int dfs(int p) {
	int res = o[p];
	for (int x : graph[p])
		if (!comp[x])
			comp[x] = comp[p],
			res += dfs(x);
	return res;
}

int main() {
	scanf("%d%d", &n, &m);
	o.assign(n, 0);
	rep(i, 0, n) scanf("%d", &o[i]);
	graph.assign(n, vi());
	while (m--) {
		int x, y; scanf("%d%d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	comp.assign(n, 0);
	int res = true;
	rep(i, 0, n) {
		if (!comp[i]) {
			comp[i] = cnt++;
			int val = dfs(i);
			res &= val == 0;
		}
	}
	if (res) printf("POSSIBLE\n");
	else printf("IMPOSSIBLE\n");
}
