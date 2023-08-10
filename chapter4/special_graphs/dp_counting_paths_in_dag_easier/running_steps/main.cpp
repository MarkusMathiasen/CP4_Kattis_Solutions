#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, t, n, M = 50;
ll dp[100][100][101]; // more 2 than right; more 2 than 1; steps left

ll calc(int n2, int n21, int s) {
	ll& res = dp[n2][n21][s];
	if (res != -1) return res;
	if (s == 0) {
		if (n2 != M || n21 < M) return res = 0;
		return res = 1;
	}
	res = 0;
	if (s >= 2)
		res += calc(n2, n21-1, s-2);
	if (s >= 3)
		res += calc(n2+1, n21, s-3),
		res += calc(n2-1, n21, s-3);
	if (s >= 4)
		res += calc(n2, n21+1, s-4);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(i, 0, 100) rep(j, 0, 100) rep(k, 0, 101)
		dp[i][j][k] = -1;
	while (T--) {
		cin >> t >> n;
		printf("%d %lld\n", t, calc(M, M, n));
	}
}
