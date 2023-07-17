#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int W = 2000;

int n;
vi w;
vector<vi> dp;

int main() {
	scanf("%d", &n);
	w.assign(n, 0);
	rep(i, 0, n) scanf("%d", &w[i]);
	dp.assign(n+1, vi(W+1, 0));
	dp[0][0] = 1;
	rep(i, 0, n) rep(j, 0, W+1) {
		if (!dp[i][j]) continue;
		dp[i+1][j] = 1;
		if (j + w[i] <= W)
			dp[i+1][j + w[i]] = 1;
	}
	int res = 2001;
	for (int i = 2000; i >= 0; i--)
		if (dp[n][i] && abs(i-1000) < abs(res-1000))
			res = i;
	printf("%d\n", res);
}
