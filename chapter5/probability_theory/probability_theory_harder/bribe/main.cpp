#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll N = 16;

int b[N], p[N];
int n, c, m, T;
double dp[1<<N][2];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
	cin >> n >> c >> m;
		rep(i, 0, n) cin >> b[i] >> p[i];
		rep(i, 0, 1<<n) dp[i][0] = 1;
		rep(j_real, 1, c+1) rep(i, 0, 1<<n) {
			int j = j_real%2;
			dp[i][j] = 0;
			int k = m;
			rep(pers, 0, n) if (!(i&(1<<pers))) k -= b[pers];
			k = max(0, k);
			int i2 = i;
			while (i2) {
				int pers = __builtin_ctz(i2);
				i2 ^= 1<<pers;
				if (k >= b[pers]) {
					dp[i][j] = max(dp[i][j],
					dp[i^(1<<pers)][(j+1)%2]*p[pers]/100
					+ dp[i^(1<<pers)][j]*(100-p[pers])/100);
				}
			}
		}
		printf("%lf\n", dp[(1<<n)-1][c%2]);
	}
}
