#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, n;
map<string, int> toi;
vector<vi> graph;

int read_ip(string& s) {
	if (!toi.count(s)) {
		toi[s] = sz(toi);
		graph.push_back(vi());
	}
	return toi[s];
}

bool bfs(int start) {
	queue<int> q;
	q.push(start);
	vi dist(n, -1);
	dist[start] = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int u : graph[v]) {
			if (dist[u] != -1) continue;
			dist[u] = dist[v]+1;
			if (dist[u] > 6) return true;
			q.push(u);
		}
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		graph.clear();
		toi.clear();
		int m; cin >> m;
		while (m--) {
			string s;
			cin >> s; int a = read_ip(s);
			cin >> s; int b = read_ip(s);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		n = sz(graph);
		int res = 0;
		rep(i, 0, n)
			res += bfs(i);
		printf(res*20 <= n ? "YES\n" : "NO\n");
	}
}
