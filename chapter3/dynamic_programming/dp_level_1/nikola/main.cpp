#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e9;

int n;
vi fees;
vector<vi> dp;

int main() {
	scanf("%d", &n);
	fees.assign(n, 0);
	rep(i, 0, n) scanf("%d", &fees[i]);
	dp.assign(n, vi(n, MAX));
	dp[0][0] = 0;
	rep(j, 0, n) for (int i = n-1; i >= 0; i--) {
		if (dp[i][j] == MAX) continue;
		if (i + j + 1 < n)
			dp[i+j+1][j+1] = min(dp[i+j+1][j+1], dp[i][j] + fees[i+j+1]);
		if (i - j >= 0)
			dp[i-j][j] = min(dp[i-j][j], dp[i][j] + fees[i-j]);
	}
	int res = MAX;
	rep(i, 0, n) res = min(res, dp[n-1][i]);
	printf("%d\n", res);
}
