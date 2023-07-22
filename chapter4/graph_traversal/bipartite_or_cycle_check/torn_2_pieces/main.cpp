#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N;
string line;
map<string, vector<string>> graph;
map<string, string> p;

void dfs(string v) {
	for (string u : graph[v])
		if (!p.count(u)) {
			p[u] = v;
			dfs(u);
		}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	getline(cin, line);
	rep(i, 0, N) {
		getline(cin, line);
		stringstream ss(line);
		string v, u; ss >> v;
		while (ss >> u)
			graph[v].push_back(u),
			graph[u].push_back(v);
	}
	string start, finish; cin >> start >> finish;
	p[start] = "";
	dfs(start);
	if (!p.count(finish)) {
		printf("no route found\n");
	} else {
		vector<string> res;
		string v = finish;
		res.push_back(v);
		while (v != start)
			v = p[v],
			res.push_back(v);
		for (int i = sz(res)-1; i >= 0; i--)
			printf("%s ", res[i].c_str());
		printf("\n");
	}
}
