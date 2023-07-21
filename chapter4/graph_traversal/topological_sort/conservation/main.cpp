#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> graph;
vi lab;

int kahn(vi& deg, int l, vector<queue<int>>& q) {
	while (!q[l].empty()) {
		int v = q[l].front(); q[l].pop();
		for (int u : graph[v]) {
			deg[u]--;
			if (deg[u] == 0)
				q[lab[u]].push(u);
		}
	}
	if (q[1-l].empty())
		return 0;
	return 1+kahn(deg, 1-l, q);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		lab.assign(n, 0);
		rep(i, 0, n) scanf("%d", &lab[i]), lab[i]--;
		vi deg(n, 0);
		graph.assign(n, vi());
		while (m--) {
			int a, b; scanf("%d%d", &a, &b); a--; b--;
			graph[a].push_back(b);
			deg[b]++;
		}
		vector<queue<int>> q(2, queue<int>());
		rep(i, 0, n)
			if (deg[i] == 0)
				q[lab[i]].push(i);
		vi deg2(deg);
		vector<queue<int>> q2(q);
		int res1 = kahn(deg, 0, q);
		int res2 = kahn(deg2, 1, q2);
		printf("%d\n", min(res1, res2));
	}
}
