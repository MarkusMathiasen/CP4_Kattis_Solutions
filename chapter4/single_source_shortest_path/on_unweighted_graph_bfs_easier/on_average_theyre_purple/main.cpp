#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<vi> graph(n, vi());
	while (m--) {
		int a, b; scanf("%d%d", &a, &b); a--, b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vi dist(n, -1);
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int u : graph[v]) {
			if (dist[u] == -1)
				dist[u] = dist[v]+1,
				q.push(u);
		}
	}
	printf("%d\n", dist[n-1]-1);
}
