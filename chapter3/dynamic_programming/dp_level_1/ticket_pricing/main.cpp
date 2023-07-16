#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, W;
vector<vi> dp;
vector<vi> pre;

int main() {
	scanf("%d%d", &N, &W);
	dp.assign(W+2, vi(N+1, -1));
	pre.assign(W+2, vi(N+1, 1e9));
	dp[0][N] = 0;
	rep(w, 0, W+1) {
		int K; scanf("%d", &K);
		vi p(K, 0), s(K, 0);
		rep(i, 0, K) scanf("%d", &p[i]);
		rep(i, 0, K) scanf("%d", &s[i]);
		rep(i, 0, N+1) {
			if (dp[w][i] == -1) continue;
			rep(j, 0, K) {
				int st = min(s[j], i);
				if (dp[w][i]+p[j]*st > dp[w+1][i-st])
					pre[w+1][i-st] = w == 0 ?
					p[j] :
					pre[w][i];
				if (dp[w][i]+p[j]*st == dp[w+1][i-st])
					pre[w+1][i-st] = min(pre[w+1][i-st],
							w == 0 ? p[j] : pre[w][i]);
				if (dp[w][i]+p[j]*st >= dp[w+1][i-st])
					dp[w+1][i-st] = dp[w][i]+p[j]*st;
			}
		}
	}
	int res = -1;
	int price = -1;
	rep(w, 0, W+2) rep(i, 0, N+1)
		if (res < dp[w][i] || (res == dp[w][i] && price > pre[w][i])) {
			res = dp[w][i];
			price = pre[w][i];
		}
	printf("%d\n%d\n", res, price);
}
