#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, cnt = 0;
unordered_map<string, int> toi;
vector<string> tos;
vector<vi> graph, trans;
vi comp;
stack<int> st;

int read_name(string& s) {
	if (!toi.count(s)) {
		toi[s] = sz(toi);
		tos.push_back(s);
		graph.push_back(vi());
		trans.push_back(vi());
	}
	return toi[s];
}

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
	cin.tie(0)->sync_with_stdio(0);
	cin >> m;
	while (m--) {
		string a, b; cin >> a >> b;
		int x = read_name(a);
		int y = read_name(b);
		graph[x].push_back(y);
		trans[y].push_back(x);
	}
	n = sz(graph);
	comp.assign(n, 0);
	rep(i, 0, n) dfs_first(i);
	comp.assign(n, -1);
	while (!st.empty()) {
		int v = st.top(); st.pop();
		dfs_second(v);
		cnt += comp[v] == cnt;
	}
	vector<vector<string>> comps(cnt, vector<string>());
	rep(i, 0, n)
		comps[comp[i]].push_back(tos[i]);
	rep(i, 0, cnt) sort(all(comps[i]));
	sort(all(comps));
	bool has_ones = false;
	rep(i, 0, cnt)
		if (sz(comps[i]) > 1) {
			printf("okay");
			for (string s : comps[i])
				printf(" %s", s.c_str());
			printf("\n");
		}
		else {
			has_ones = true;
			assert(sz(comps[i]) == 1);
		}
	if (has_ones) {
		printf("avoid");
		rep(i, 0, cnt)
			if (sz(comps[i]) == 1)
				printf(" %s", (*comps[i].begin()).c_str());
		printf("\n");
	}
}
