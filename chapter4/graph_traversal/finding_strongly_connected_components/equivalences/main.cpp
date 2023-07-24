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
vi comp;
stack<int> st;

void dfs_first(int v) {
	if (comp[v] != -1) return;
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
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		graph.assign(n, vi());
		trans.assign(n, vi());
		while (m--) {
			int a, b; scanf("%d%d", &a, &b); a--, b--;
			graph[a].push_back(b);
			trans[b].push_back(a);
		}
		comp.assign(n, -1);
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
		vi has_in(cnt, 0), has_out(cnt, 0);
		rep(v, 0, n)
			for (int u : graph[v])
				if (comp[v] != comp[u])
					has_out[comp[v]] = has_in[comp[u]] = 1;
		int in = 0, out = 0;
		rep(i, 0, cnt)
			in += has_in[i] == 0,
			out += has_out[i] == 0;
		if (cnt == 1)
			printf("0\n");
		else
			printf("%d\n", max(in, out));
	}
}
