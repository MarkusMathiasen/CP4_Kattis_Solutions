#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map<string, int> toi;
unordered_map<int, string> tos;
vector<vi> graph;
int n, cnt=-1;
vector<string> topo;
vi vis;

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : graph[v])
		dfs(u);
	topo.push_back(tos[v]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	graph.assign(n, vi());
	rep(i, 0, n) {
		string s1; cin >> s1; s1.pop_back();
		if (!toi.count(s1)) {
			toi[s1] = ++cnt;
			tos[cnt] = s1;
		}
		string line; getline(cin, line);
		stringstream ss(line);
		string s2;
		while (ss >> s2) {
			if (!toi.count(s2)) {
				toi[s2] = ++cnt;
				tos[cnt] = s2;
			}
			graph[toi[s2]].push_back(toi[s1]);
		}
	}
	string s; cin >> s;
	vis.assign(n, 0);
	dfs(toi[s]);
	for (int i = sz(topo)-1; i >= 0; i--)
		printf("%s\n", topo[i].c_str());
}
