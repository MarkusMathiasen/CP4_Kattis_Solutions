#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string line, s1, s2, s3;
int start;
vector<string> tos;
map<string, int> toi;
vector<vi> graph;
vi vis;

int read_name(string& s) {
	if (!toi.count(s)) {
		toi[s] = sz(toi);
		tos.push_back(s);
		graph.push_back(vi());
	}
	return toi[s];
}

int dfs(int v) {
	if (vis[v] && v == start) return 2;
	if (vis[v]) return 1;
	vis[v] = 1;
	int res = 0;
	for (int u : graph[v])
		res = max(res, dfs(u));
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (getline(cin, line)) {
		if (line != "done") {
			stringstream ss(line);
			ss >> s1 >> s2 >> s3;
			int p = read_name(s1);
			int c = read_name(s3);
			graph[c].push_back(p);
		}
		else {
			for (auto [s,i] : toi) {
				start = i;
				vis.assign(sz(tos), 0);
				int res = dfs(i);
				if (res == 1) printf("%s hillbilly\n", s.c_str());
				if (res == 2) printf("%s paradox\n", s.c_str());
			}
			printf("\n");
			// reset everything
			tos.clear();
			toi.clear();
			graph.clear();
			vis.clear();
		}
	}
}
