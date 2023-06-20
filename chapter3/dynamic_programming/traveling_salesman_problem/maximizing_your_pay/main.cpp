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
vector<vi> dp;

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		graph.assign(n, vi(n, 0));
		rep(i, 0, m) {
			int a, b; scanf("%d%d", &a, &b);
			graph[a][b] = graph[b][a] = 1;
		}
		graph[0][0] = 1;
		dp.assign(1 << n, vi(n, 0));
		dp[1][0] = 1;
		int res = 0;
		rep(mask, 0, 1<<n) rep(v, 0, n) {
			if (!((1 << v) & mask)) continue;
			if (!dp[mask][v]) continue;
			if (graph[v][0]) res = max(res, __builtin_popcount(mask));
			rep(u, 0, n) {
				if ((1 << u) & mask) continue;
				if (graph[v][u]) dp[mask | (1 << u)][u] = 1;
			}
		}
		printf("%d\n", res);
	}
}
