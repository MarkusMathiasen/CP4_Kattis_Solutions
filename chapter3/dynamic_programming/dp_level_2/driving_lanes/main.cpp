#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, k, r;
vi l, s, c;
vector<vi> dp;

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &r);
	l.assign(n, 0); s.assign(n-1, 0); c.assign(n-1, 0);
	rep(i, 0, n) scanf("%d", &l[i]);
	rep(i, 0, n-1) scanf("%d%d", &s[i], &c[i]);
	dp.assign(n, vi(m, 1e9));
	rep(j, 0, m) {
		if (k*j > l[0]) break;
		dp[0][j] = l[0] + r*j;
	}
	rep(i, 1, n) rep(j, 0, m) {
		int& d = dp[i][j];
		rep(pj, 0, m) {
			if (k*abs(j-pj) > l[i]) continue;
			d = min(d, dp[i-1][pj] + s[i-1] + c[i-1]*(pj+1) + l[i] + r*abs(j-pj));
		}
	}
	printf("%d\n", dp[n-1][0]);
}
