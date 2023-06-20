#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;

int fill_dp(vector<vi>& dp, vector<vi>& graph, int mask, int v) {
	if (dp[mask][v] != -1) return dp[mask][v];
	int res = 0;
	rep(u, 0, n)
		if (((1 << u) & mask) == 0 && graph[v][u])
			res += fill_dp(dp, graph, mask | (1<<u), u);
	return dp[mask][v] = res;
}

void pp(vector<vi>& dp) {
	rep(row, 0, sz(dp)) {
		vi& v = dp[row];
		for (int i = 0; (1 << i) < sz(dp); i++)
			printf("%d", ((1 << i) & row) != 0);
		printf(": ");
		for (int x : v)
			printf("%3d", x);
		printf("\n");
	}
}

int main() {
	int T; scanf("%d", &T);
	rep(t, 1, T+1) {
		scanf("%d%d", &n, &k);
		vector<vi> graph(n, vi(n, 1));
		rep(i, 0, k) {
			int a, b; scanf("%d%d", &a, &b); a--; b--;
			graph[a][b] = graph[b][a] = 0;
		}
		vector<vi> dp(1 << n, vi(n, -1));
		rep(i, 1, n) dp[(1 << n)-1][i] = graph[i][0];
		fill_dp(dp, graph, 1, 0);
		printf("Case #%d: %d\n", t, (dp[1][0]/2)%9901);
	}
}
