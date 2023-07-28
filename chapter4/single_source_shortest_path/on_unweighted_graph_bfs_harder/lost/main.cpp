#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<string> tos = {"English"};
map<string, int> toi = {{"English", 0}};
vi cost;
vector<vector<pii>> graph;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	rep(i, 1, n+1) {
		string s; cin >> s; tos.push_back(s);
		toi[s] = i;
	}
	graph.assign(n+1, vector<pii>());
	while (m--) {
		string a, b; int c; cin >> a >> b >> c;
		graph[toi[a]].push_back({toi[b], c});
		graph[toi[b]].push_back({toi[a], c});
	}
	cost.assign(n+1, -1);
	vi dist(n+1, -1);
	cost[0] = dist[0] = 0;
	queue<int> q;
	q.push(0);
	int res = 0;
	int cnt = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		res += cost[v];
		cnt++;
		for (auto [u,w] : graph[v]) {
			if (dist[u] == -1)
				dist[u] = dist[v]+1,
				q.push(u);
			if (dist[u] == dist[v]+1 && (cost[u] > w || cost[u] == -1))
				cost[u] = w;
		}
	}
	if (cnt != n+1) printf("Impossible\n");
	else printf("%d\n", res);
}
