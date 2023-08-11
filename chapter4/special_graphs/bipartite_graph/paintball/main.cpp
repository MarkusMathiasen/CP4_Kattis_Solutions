#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<vi> graph;
vi vis, match;

int mcbm(int v, int visi) {
	if (vis[v] == visi) return 0;
	vis[v] = visi;
	for (int u : graph[v]) {
		if (match[u] == -1 || mcbm(match[u], visi)) {
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	graph.assign(n, {});
	rep(i, 0, m) {
		int a, b; cin >> a >> b; a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	match.assign(n, -1);
	vis.assign(n, -1);
	int res = 0;
	rep(i, 0, n) res += mcbm(i, i);
	if (res == n)
		rep(i, 0, n)
			printf("%d\n", match[i]+1);
	else printf("Impossible\n");
}
