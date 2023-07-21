#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct edge {
	int v, l, u; // destination, lower and upper
};

int N, L, B, S, D;
vector<vector<edge>> graph;
vector<bool> vis;
vi lows, ups;

bool dfs(int v, int b) {
	if (v == D) return true;
	if (vis[v]) return false;
	vis[v] = true;
	for (edge e : graph[v])
		if (e.l <= b && b <= e.u)
			if (dfs(e.v, b))
				return true;
	return false;
}

int main() {
	scanf("%d%d%d%d%d", &N, &L, &B, &S, &D); S--, D--;
	graph.assign(N, vector<edge>());
	while (L--) {
		int a, b, l, u; scanf("%d%d%d%d", &a, &b, &l, &u); a--; b--;
		graph[a].push_back({b, l, u});
		lows.push_back(l);
		ups.push_back(u);
	}
	sort(all(lows));
	sort(all(ups));
	int l = 0, u = 0, b = 0, res = 0;
	bool reachable = false;
	while (u < sz(ups)) {
		if (l < sz(lows) && lows[l] <= ups[u]) {
			if (!reachable) {
				vis.assign(N, 0);
				bool reach = dfs(S, lows[l]);
				if (!reachable && reach)
					b = lows[l];
				reachable |= reach;
			}
			l++;
		} else {
			if (reachable) {
				vis.assign(N, 0);
				bool reach = dfs(S, ups[u]+1);
				if (reachable && !reach)
					res += ups[u]+1-b;
				reachable &= reach;
			}
			u++;
		}
	}
	printf("%d\n", res);
}
