#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> tos, order;
unordered_map<string, int> toi;
vector<vi> graph;

int read_name(string& s) {
	if (!toi.count(s)) {
		toi[s] = sz(toi);
		tos.push_back(s);
		graph.push_back(vi());
	}
	return toi[s];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string line;
	while (getline(cin, line) && line != "") {
		stringstream ss(line);
		string s; ss >> s;
		int a = read_name(s);
		order.push_back(s);
		while (ss >> s) {
			int b = read_name(s);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	}
	int n = sz(toi);
	vi dist(n, -1);
	int paul = toi["PAUL_ERDOS"];
	dist[paul] = 0;
	queue<int> q;
	q.push(paul);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int u : graph[v]) {
			if (dist[u] == -1) {
				dist[u] = dist[v]+1;
				q.push(u);
			}
		}
	}
	for (string& s : order) {
		printf("%s ", s.c_str());
		if (dist[toi[s]] != -1)
			printf("%d\n", dist[toi[s]]);
		else 
			printf("no-connection\n");
	}
}
