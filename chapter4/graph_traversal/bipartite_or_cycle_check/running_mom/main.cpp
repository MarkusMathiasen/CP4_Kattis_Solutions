#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
unordered_map<string, int> toi;
vector<string> tos;
vector<vi> graph;
vi vis;

int read_city() {
	string s; cin >> s;
	if (!toi.count(s)) {
		toi[s] = sz(tos);
		tos.push_back(s);
	}
	return toi[s];
}

bool has_cycle(int v) {
	if (vis[v] == 1) return true;
	if (vis[v] == 2) return false;
	vis[v] = 1;
	for (int u : graph[v])
		if (has_cycle(u))
			return true;
	vis[v] = 2;
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	graph.assign(2*n, vi());
	rep(i, 0, n) {
		int a = read_city(), b = read_city();
		graph[a].push_back(b);
	}
	string s;
	while (cin >> s) {
		printf("%s ", s.c_str());
		vis.assign(2*n, 0);
		if (has_cycle(toi[s]))
			printf("safe\n");
		else
			printf("trapped\n");
	}
}
