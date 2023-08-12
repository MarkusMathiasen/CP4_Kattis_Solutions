#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
unordered_map<string, int> toi;
vector<string> tos;
vector<vi> graph;
vi in_deg, out_deg, vis;

int read_name(string& s) {
	if (!toi.count(s)) {
		toi[s] = sz(toi);
		tos.push_back(s);
	}
	return toi[s];
}

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : graph[v])
		dfs(u);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	in_deg.assign(n, 0);
	out_deg.assign(n, 0);
	graph.assign(n, {});
	rep(i, 0, n) {
		string s; cin >> s;
		int v = read_name(s);
		int k; cin >> k;
		while (k--) {
			cin >> s;
			int u = read_name(s);
			if (v == u) continue;
			graph[v].push_back(u);
			in_deg[u]++;
			out_deg[v]++;
		}
	}
	bool alarm = false;
	rep(i, 0, n) alarm |= in_deg[i] | out_deg[i];
	if (!alarm) {
		printf("FALSE ALARM\n");
		return 0;
	}
	bool possible = true;
	int start = -1, goal = -1;
	rep(i, 0, n) {
		if (in_deg[i] == out_deg[i]) continue;
		else if (in_deg[i]+1 == out_deg[i] && start == -1) start = i;
		else if (in_deg[i] == out_deg[i]+1 && goal == -1) goal = i;
		else possible = false;
	}
	if (start == -1) rep(i, 0, n) if (sz(graph[i])) start = i;
	vis.assign(n, 0);
	dfs(start);
	rep(i, 0, n) possible &= vis[i] || !sz(graph[i]);
	if (!possible) printf("IMPOSSIBLE\n");
	else printf("POSSIBLE\n");
}
