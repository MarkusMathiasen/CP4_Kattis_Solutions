#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
string line;
vector<string> tos, topo;
unordered_map<string, int> toi;
vector<vector<string>> s_graph;
vector<vi> graph;
vi deg;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n, n) {
		getline(cin, line);
		s_graph.assign(n, vector<string>());
		graph.assign(n, vi());
		topo.clear();
		deg.assign(n, 0);
		tos.assign(n, "");
		toi.clear();
		rep(i, 0, n) {
			getline(cin, line);
			stringstream ss(line);
			ss >> tos[i];
			toi[tos[i]] = i;
			string s;
			while (ss >> s)
				s_graph[i].push_back(s);
		}
		rep(i, 0, n)
			for (string& s : s_graph[i])
				graph[toi[s]].push_back(i),
				deg[i]++;
		priority_queue<string, vector<string>, greater<string>> pq;
		rep(i, 0, n) if (deg[i] == 0) pq.push(tos[i]);
		while (!pq.empty()) {
			string s = pq.top(); pq.pop();
			topo.push_back(s);
			for (int u : graph[toi[s]]) {
				deg[u]--;
				if (deg[u] == 0)
					pq.push(tos[u]);
			}
		}
		if (sz(topo) < n)
			printf("cannot be ordered\n");
		else
			for (string& s : topo)
				printf("%s\n", s.c_str());
		printf("\n");
	}
}
