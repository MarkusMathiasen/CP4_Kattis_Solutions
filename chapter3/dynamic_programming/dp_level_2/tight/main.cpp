#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<long double>> dp;

int main() {
	int k, n;
	while (scanf("%d%d", &k, &n) == 2) {
		dp.assign(n+1, vector<long double>(k+1, 0));
		rep(i, 0, 2) rep(j, 0, k+1) dp[i][j] = 1;
		rep(i, 1, n) rep(j, 0, k+1) {
			if (j < k) dp[i+1][j+1] += dp[i][j]/(k+1);
			dp[i+1][j] += dp[i][j]/(k+1);
			if (j > 0) dp[i+1][j-1] += dp[i][j]/(k+1);
		}
		long double res = 0;
		rep(i, 0, k+1) res += dp[n][i];
		printf("%.8Lf\n", res/(k+1)*100);
	}
}
