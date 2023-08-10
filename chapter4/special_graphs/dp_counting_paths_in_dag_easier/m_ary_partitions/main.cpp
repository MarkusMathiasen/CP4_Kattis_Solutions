#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, t, n, m;
vector<vi> dp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> t >> m >> n;
		int P = 1, tmp = 1;
		while (tmp <= n) P++, tmp *= m;
		dp.assign(n+1, vi(P, 0));
		rep(i, 0, P) dp[0][i] = 1;
		rep(p, 0, P) rep(i, 1, n+1) {
			int k = 1;
			rep(j, 0, p) k *= m;
			if (k <= i)
				dp[i][p] += dp[i-k][p];
			if (p)
				dp[i][p] += dp[i][p-1];
		}
		
		printf("%d %d\n", t, dp[n][P-1]);
	}
}
