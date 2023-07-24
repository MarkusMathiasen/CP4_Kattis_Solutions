#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, n, m, cnt;
vector<vi> graph, trans;
vi vis, comp;
stack<int> st;

void dfs_first(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : graph[v])
		dfs_first(u);
	st.push(v);
}

void dfs_second(int v) {
	if (comp[v] != -1) return;
	comp[v] = cnt;
	for (int u : trans[v])
		dfs_second(u);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		graph.assign(n, vi());
		trans.assign(n, vi());
		while (m--) {
			int x, y; scanf("%d%d", &x, &y); x--; y--;
			graph[x].push_back(y);
			trans[y].push_back(x);
		}
		vis.assign(n, 0);
		rep(i, 0, n) dfs_first(i);
		comp.assign(n, -1);
		cnt = 0;
		while (!st.empty()) {
			int v = st.top(); st.pop();
			dfs_second(v);
			cnt += comp[v] == cnt;
		}
		vi has_ingoing(cnt, 0);
		rep(v, 0, n)
			for (int u : graph[v])
				if (comp[v] != comp[u])
					has_ingoing[comp[u]] = 1;
		int res = cnt;
		for (int x : has_ingoing)
			res -= x;
		printf("%d\n", res);
	}
}
