#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_H = 1000;
const int INF = 1e9;

int T, n;
vi dists;
vector<vi> dp;
vector<vi> pre;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		dists.assign(n, 0);
		rep(i, 0, n) scanf("%d", &dists[i]);
		dp.assign(n+1, vi(MAX_H+1, INF));
		pre.assign(n+1, vi(MAX_H+1, INF));
		dp[0][0] = 0;
		rep(i, 1, n+1) rep(h, 0, MAX_H) {
			int dp_down = h - dists[i-1] >= 0 ? dp[i-1][h-dists[i-1]] : INF;
			int dp_up = h + dists[i-1] <= MAX_H ? dp[i-1][h+dists[i-1]] : INF;
			if (dp_down != INF)
				dp[i][h] = max(h, dp_down),
				pre[i][h] = h-dists[i-1];
			if (dp_up != INF && dp_up < dp[i][h])
				dp[i][h] = dp_up,
				pre[i][h] = h+dists[i-1];
		}
		// Print solution
		if (dp[n][0] == INF)
			printf("IMPOSSIBLE\n");
		else {
			vector<char> res;
			int h = 0;
			for (int i = n; i > 0; i--) {
				res.push_back(pre[i][h] > h ? 'D' : 'U');
				h = pre[i][h];
			}
			for (int i = n-1; i >= 0; i--)
				printf("%c", res[i]);
			printf("\n");
		}
	}
}
