#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
map<int, int> top;
vector<vector<pii>> graph;
vi vis;
vector<tuple<int, int, int>> res;

int read_num(int num, int pers) {
	if (!top.count(num))
		top[num] = pers;
	return top[num];
}

void dfs(int v) {
	vis[v] = 1;
	for (auto [u,w] : graph[v]) {
		if (!vis[u]) {
			vis[u] = 1;
			res.push_back({v, u, w});
			dfs(u);
		}
	}
}

int main() {
	scanf("%d", &n);
	graph.assign(n, vector<pii>());
	rep(i, 0, n) {
		int m; scanf("%d", &m);
		while (m--) {
			int num; scanf("%d", &num);
			int p = read_num(num, i);
			if (p != i) {
				graph[i].push_back({p, num});
				graph[p].push_back({i, num});
			}
		}
	}
	vis.assign(n, 0);
	dfs(0);
	if (sz(res) == n-1) {
		for (auto [a,b,w] : res)
			printf("%d %d %d\n", a+1, b+1, w);
	}
	else printf("impossible\n");
}
