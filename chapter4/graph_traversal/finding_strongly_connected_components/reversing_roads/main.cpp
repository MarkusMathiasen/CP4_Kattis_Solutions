#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, cnt;
vector<vi> graph, trans;
vector<pii> edges;
vi comp;
stack<int> st;

void dfs_first(int v) {
	if (comp[v]) return;
	comp[v] = 1;
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
	int t = 0;
	while (scanf("%d%d", &n, &m) == 2) {
		graph.assign(n, vi());
		trans.assign(n, vi());
		edges.clear();
		while (m--) {
			int a, b; scanf("%d%d", &a, &b);
			graph[a].push_back(b);
			trans[b].push_back(a);
			edges.emplace_back(a, b);
		}
		comp.assign(n, 0);
		rep(i, 0, n) dfs_first(i);
		comp.assign(n, -1);
		cnt = 0;
		while (!st.empty()) {
			int v = st.top(); st.pop();
			if (comp[v] == -1) {
				dfs_second(v);
				cnt++;
			}
		}
		printf("Case %d: ", ++t);
		if (cnt == 1)
			printf("valid\n");
		else {
			vi in_deg(cnt, 0), out_deg(cnt, 0);
			int root = -1, leaf = -1;
			int root_cnt = 0, leaf_cnt = 0;
			for (auto [a,b] : edges) {
				if (comp[a] == comp[b]) continue;
				in_deg[comp[b]]++;
				out_deg[comp[a]]++;
			}
			rep(i, 0, cnt) {
				if (out_deg[i] == 0)
					leaf_cnt++,
					leaf = i;
				if (in_deg[i] == 0)
					root_cnt++,
					root = i;
			}
			if (leaf_cnt != 1 || root_cnt != 1)
				leaf = root = -1;
			int start = -1, fin = -1;
			for (auto [a,b] : edges) {
				if (comp[a] == root && comp[b] == leaf) {
					start = a;
					fin = b;
					break;
				}
			}
			if (start != -1)
				printf("%d %d\n", start, fin);
			else
				printf("invalid\n");
		}
	}
}
