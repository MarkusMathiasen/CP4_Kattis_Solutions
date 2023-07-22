#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, d, res = 0;
unordered_map<string, int> toi;
vector<vi> graph;
vi t, vis;

void day(queue<int>& q1, queue<int>& q2) {
	while (!q1.empty()) {
		int v = q1.front(); q1.pop();
		for (int u : graph[v]) {
			t[u]--;
			if (!vis[u])
				res++, vis[u] = 1;
			if (vis[u] == 1 && t[u] <= 0)
				vis[u] = 2,
				q2.push(u);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> d;
	t.assign(n, 0);
	vis.assign(n, 0);
	graph.assign(n, vi());
	rep(i, 0, n) {
		string s; cin >> s >> t[i];
		toi[s] = i;
	}
	while (m--) {
		string s1, s2; cin >> s1 >> s2;
		graph[toi[s1]].push_back(toi[s2]);
		graph[toi[s2]].push_back(toi[s1]);
	}
	string s; cin >> s;
	queue<int> q1, q2; q1.push(toi[s]);
	vis[toi[s]] = 2;
	rep(i, 0, d) {
		if (i%2 == 0)
			day(q1, q2);
		else
			day(q2, q1);
	}
	printf("%d\n", res);
}
